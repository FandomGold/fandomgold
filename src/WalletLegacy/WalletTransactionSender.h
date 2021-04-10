// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, Karbo developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2018-2019 Conceal Network & Conceal Devs
// Copyright (c) 2017-2021 Fandom Gold Society
//
// This file is part of Fango.
//
// FANGO is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// FANGO is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License
// along with FANGO.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "CryptoNoteCore/Account.h"
#include "CryptoNoteCore/Currency.h"

#include "INode.h"
#include "WalletLegacy/WalletSendTransactionContext.h"
#include "WalletLegacy/WalletUserTransactionsCache.h"
#include "WalletLegacy/WalletUnconfirmedTransactions.h"
#include "WalletLegacy/WalletRequest.h"

#include "ITransfersContainer.h"

namespace CryptoNote {

class WalletTransactionSender
{
public:
  WalletTransactionSender(const Currency& currency, WalletUserTransactionsCache& transactionsCache, AccountKeys keys, ITransfersContainer& transfersContainer);

  void stop();

  std::shared_ptr<WalletRequest> makeSendRequest(Crypto::SecretKey& txSecretKey,TransactionId& transactionId, std::deque<std::shared_ptr<WalletLegacyEvent>>& events,
    const std::vector<WalletLegacyTransfer>& transfers, uint64_t fee, const std::string& extra = "", uint64_t mixIn = 0, uint64_t unlockTimestamp = 0);

  std::unique_ptr<WalletRequest> makeDepositRequest(Crypto::SecretKey& txSecretKey,/*<=???*/TransactionId& transactionId,
                                                    std::deque<std::unique_ptr<WalletLegacyEvent>>& events,
                                                    uint64_t term,
                                                    uint64_t amount,
                                                    uint64_t fee,
                                                    uint64_t mixIn = 0);

  std::unique_ptr<WalletRequest> makeWithdrawDepositRequest(TransactionId& transactionId,
                                                            std::deque<std::unique_ptr<WalletLegacyEvent>>& events,
                                                            const std::vector<DepositId>& depositIds,
                                                            uint64_t fee);

private:
   std::unique_ptr<WalletRequest> makeGetRandomOutsRequest(std::shared_ptr<SendTransactionContext>&& context, bool isMultisigTransaction, Crypto::SecretKey& txSecretKey);
  std::unique_ptr<WalletRequest> doSendTransaction(std::shared_ptr<SendTransactionContext>&& context, std::deque<std::unique_ptr<WalletLegacyEvent>>& events, Crypto::SecretKey& txSecretKey);
  std::unique_ptr<WalletRequest> doSendMultisigTransaction(std::shared_ptr<SendTransactionContext>&& context, std::deque<std::unique_ptr<WalletLegacyEvent>>& events);
  std::unique_ptr<WalletRequest> doSendDepositWithdrawTransaction(std::shared_ptr<SendTransactionContext>&& context,
                                                                  std::deque<std::unique_ptr<WalletLegacyEvent>>& events,
                                                                  const std::vector<DepositId>& depositIds);

  /*void prepareInputs(const std::list<TransactionOutputInformation>& selectedTransfers, std::vector<COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount>& outs,
      std::vector<TransactionSourceEntry>& sources, uint64_t mixIn);*/


 /* void sendTransactionRandomOutsByAmount(std::shared_ptr<SendTransactionContext> context, std::deque<std::shared_ptr<WalletLegacyEvent>>& events,
      boost::optional<std::shared_ptr<WalletRequest> >& nextRequest, std::error_code ec);*/

   void sendTransactionRandomOutsByAmount(bool isMultisigTransaction,
                                         std::shared_ptr<SendTransactionContext> context,
                                         Crypto::SecretKey& txSecretKey,
                                         std::deque<std::unique_ptr<WalletLegacyEvent>>& events,
                                         std::unique_ptr<WalletRequest>& nextRequest,
                                         std::error_code ec);

  void prepareKeyInputs(const std::vector<TransactionOutputInformation>& selectedTransfers,
                        std::vector<COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount>& outs,
                        std::vector<TransactionSourceEntry>& sources,
                        uint64_t mixIn);
  std::vector<TransactionTypes::InputKeyInfo> prepareKeyInputs(const std::vector<TransactionOutputInformation>& selectedTransfers,
                                                               std::vector<COMMAND_RPC_GET_RANDOM_OUTPUTS_FOR_AMOUNTS::outs_for_amount>& outs,
                                                               uint64_t mixIn);
  

  std::vector<MultisignatureInput> prepareMultisignatureInputs(const std::vector<TransactionOutputInformation>& selectedTransfers);
  void splitDestinations(TransferId firstTransferId, size_t transfersCount, const TransactionDestinationEntry& changeDts,
    const TxDustPolicy& dustPolicy, std::vector<TransactionDestinationEntry>& splittedDests);
  void digitSplitStrategy(TransferId firstTransferId, size_t transfersCount, const TransactionDestinationEntry& change_dst, uint64_t dust_threshold,
    std::vector<TransactionDestinationEntry>& splitted_dsts, uint64_t& dust);
  void relayTransactionCallback(std::shared_ptr<SendTransactionContext> context, 
                                std::deque<std::shared_ptr<WalletLegacyEvent>>& events,
                                boost::optional<std::shared_ptr<WalletRequest> >& nextRequest,
                                std::error_code ec);
  void relayDepositTransactionCallback(std::shared_ptr<SendTransactionContext> context,
                                       std::vector<DepositId> deposits,
                                       std::deque<std::unique_ptr<WalletLegacyEvent>>& events,
                                       std::unique_ptr<WalletRequest>& nextRequest,
                                       std::error_code ec);
  void notifyBalanceChanged(std::deque<std::shared_ptr<WalletLegacyEvent>>& events);

  void validateTransfersAddresses(const std::vector<WalletLegacyTransfer>& transfers);
  bool validateDestinationAddress(const std::string& address);

/*uint64_t selectNTransfersToSend(std::vector<TransactionOutputInformation>& selectedTransfers);*/
  uint64_t selectTransfersToSend(uint64_t neededMoney, bool addDust, uint64_t dust, std::list<TransactionOutputInformation>& selectedTransfers);
  uint64_t selectDepositTransfers(const std::vector<DepositId>& depositIds, std::vector<TransactionOutputInformation>& selectedTransfers);
  void setSpendingTransactionToDeposits(TransactionId transactionId, const std::vector<DepositId>& depositIds);

  const Currency& m_currency;
  AccountKeys m_keys;
  WalletUserTransactionsCache& m_transactionsCache;
  uint64_t m_upperTransactionSizeLimit;

  bool m_isStoping;
  ITransfersContainer& m_transferDetails;
};

} /* namespace CryptoNote */
