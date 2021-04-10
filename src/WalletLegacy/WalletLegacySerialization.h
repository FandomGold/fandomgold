// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2021 Conceal Network & Conceal Devs
// Copyright (c) 2017-2021 Fandom Gold Society
//
// This file is part of Fango.
//
// Fango is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Fango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License
// along with Fango.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <stdexcept>
#include <algorithm>
#include <string>

#include "IWalletLegacy.h"

namespace CryptoNote {
class ISerializer;

struct UnconfirmedTransferDetails;
struct WalletLegacyTransaction;
struct WalletLegacyTransfer;
struct DepositInfo;
struct Deposit;
struct UnconfirmedSpentDepositDetails;

void serialize(UnconfirmedTransferDetails& utd, ISerializer& serializer);
void serialize(UnconfirmedSpentDepositDetails& details, ISerializer& serializer);
void serialize(WalletLegacyTransaction& txi, ISerializer& serializer);
void serialize(WalletLegacyTransfer& tr, ISerializer& serializer);
void serialize(DepositInfo& depositInfo, ISerializer& serializer);
void serialize(Deposit& deposit, ISerializer& serializer);

}
