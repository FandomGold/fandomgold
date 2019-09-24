// Copyright (c) 2012-2016, The CryptoNote developers 
// Copyright (c) 2012-2016, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero project
// Copyright (c) 2014-2018, The Forknote developers
// Copyright (c) 2016-2019, The Karbowanec developers
// Copyright (c) 2018-2019, The Ryo Currency developers
// Copyright (c) 2017-2019, The Fandom GOLD Developers
//
// This file is part of Fandom GOLD.
// FandomG OLD is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Fandom GOLD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License
// along with Fandom GOLD.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>

namespace CryptoNote {
namespace parameters {



const uint64_t DIFFICULTY_TARGET                             = 81;//sec    **increase to 480; sec (8 min)
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 679385; // all public addresses begin w/ "dRGL" (872372 = XDG/XDG1)
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
  
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V1         = DIFFICULTY_TARGET * 6;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60; 
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V1          = 11;


const uint64_t MONEY_SUPPLY                                  = UINT64_C(80000088000008);
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 7;
const size_t   CRYPTONOTE_COIN_VERSION                       = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 800000; //size of block (bytes) after reward for block is calculated in block-size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 800000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 18;  // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = 60;  // blocks

const uint64_t MINIMUM_FEE                                   = UINT64_C(800000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(8000);

const uint64_t MIN_TX_MIXIN_SIZE                             =  2;
const uint64_t MAX_TX_MIXIN_SIZE                             = 18;

const size_t   DIFFICULTY_CUT                                = 60;  // v1
const size_t   DIFFICULTY_LAG                                = 15;  // v1
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

static constexpr uint64_t POISSON_CHECK_TRIGGER = 10; // Reorg size that triggers poisson timestamp check
static constexpr uint64_t POISSON_CHECK_DEPTH = 60;   // Main-chain depth of poisson check. The attacker will have to tamper 50% of those blocks
static constexpr double POISSON_LOG_P_REJECT = -75.0; // Reject reorg if probability of timestamps being genuine is less than e^x, -75 = 10^-33

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 800000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;
  
const uint32_t UPGRADE_HEIGHT_V2                             = 147958; //{Hardhome}
const uint32_t UPGRADE_HEIGHT_V3                             = 154321; //{Longclaw}
const uint32_t UPGRADE_HEIGHT_V4                             = 300000; //{Dracarys}
const uint32_t UPGRADE_HEIGHT_V5                             = 324819; //{Ironborn}  CN7  (variant1) 
const uint32_t UPGRADE_HEIGHT_V6                             = 345678; //{Ice&fire}  CN8  (variant2)
const uint32_t UPGRADE_HEIGHT_V7                             = 615000; //FandomGOLD
  
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "dragonglass"; 
const char     GENESIS_COINBASE_TX_HEX[]                     = "013c01ff0001b4bcc29101029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101bd4e0bf284c04d004fd016a21405046e8267ef81328cabf3017c4c24b273b25a";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;
const uint8_t  BLOCK_MAJOR_VERSION_6                         =  6;
const uint8_t  BLOCK_MAJOR_VERSION_7                         =  7;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks-ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, block count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  10818;
const int      RPC_DEFAULT_PORT                              =  18180;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 80;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // 60 sec
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 secs
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 secs
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 mins
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 secs
const uint32_t P2P_FAILED_ADDR_FORGET_SECONDS                = (45 * 60);     // 45 hr
const uint32_t P2P_IP_BLOCKTIME                              = (60 * 60 * 24);// 24 hr
const uint32_t P2P_IP_FAILS_BEFORE_BLOCK                     =  45;
const uint32_t P2P_IDLE_CONNECTION_KILL_INTERVAL             = (45 * 60);     // 45 min
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = {
"104.236.0.16:10818",
"188.226.177.187:10818",
"178.128.164.245:10818",
"176.223.134.27:10818",  
};


}

#define ALLOW_DEBUG_COMMANDS
//Knowledge has made you powerful but there is still so much you don't know.