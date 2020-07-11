// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2016-2018, The Karbowanec developers
// Copyright (c) 2018-2019, The Fandom Gold developers
//
// This file is part of Fandom Gold.
//
// Fandom Gold is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Fandom Gold is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Fandom Gold.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
{ 800,    "c1c64f752f6f5f6f69671b3794f741af0707c71b35302ea4fc96b0befdce8ce9" },
{ 8008,   "299702f163995cd790b5c45362c78ad596f8717d749ff9016ce27eaa625b8a5e" },
{ 18008,  "46baf8aea2b9472a9f127ad7cdcb01a871ecf20d710e9e0d3a2b13176a452112" },
{ 63312,  "57c815dd1480b6a1de7037f85aa510ff7c784b91808f3777451c030d40614ddb" },
{ 80008,  "19e65aec81a283e756c9b55a884927bcbffa4639c9fe21fd4894ef211e0e8472" },
{ 108801, "0cb48287678f9df42a63c6c344f448ddce5316f9c5c03548e77d9a1193ebf5fd" },
{ 147959, "cecc0692782cd1956fb12bf170c4ebd6c7b6bb5c12e7071ef2d98e7c940f1961" },
{ 148000, "bd318f33b5f1804bc648ce847d4214cff8cfd7498483461db660a87e342eb0e9" },
{ 154322, "73232b04d18cdc9cc6430194298166c6e775a55ff0f48e2f819f8ed5fd873df7" },
{ 155433, "89be8af3d0a62454e95cf71cf7c17df9480ac337b4b5a294e0d75400b8989700" },
{ 158000, "153b22f4912d1a6db9f235de40ae2be3a178eb44cbde8e2a4fe0c7727037ab34" },
{ 180018, "3c0c6fd2f6c2805280f2079f50f772433957fae495ad81e305835bdb935fd21e" },
{ 200000, "4c4555f73e54b43f62fe26950d3c7f877e35c448a1e865b5ea07aa09d971e0e5" },
{ 222222, "801d187ca11851d0379c0fa4a790d26aa24e76835d26bf7e54f4b858bfd7ad53" },
{ 250000, "1a2cfc1c53a62038468feff7f22a150a95ba65090842d09fadd97f789e1e00fc" },
{ 260000, "968fc54cd727b5d70c4ccc1f9fe144c58bd909acc97cd27c491c4f6fc1b97087" },
{ 280000, "fa6016236d07c8a5ab660f5ddd788f2f002bd518146e2bc379dd66d1bc7f94a8" },
{ 300001, "ba7e401c03a9f5b2111ef402d8715761990ff53e31069c413f5c78c7cd819de9" },
{ 320000, "2c42f527960ce443ffa645b0af85d85bdf10cf9df8625d900b4edd0b29b68735" },
{ 324820, "99fb6b6c81c9ceff7bcdef0667cf270a5300dec6393de21bd599d414eef38569" },
{ 333333, "d58919713e37e4317a3e50c12639fe591958d2e43637cf8f99f596c6c8275241" },
{ 342600, "cae28d470dddbc42fbc0f0a9d3345add566f23dea8130c9ae900697d0e1580c9" },
{ 345679, "8ce385e3816ce48adfe13952e010d1207eaf006e366e67c65f0e19cd1a550ce1" },
{ 369369, "e32cf1e1b365690fb95544ce35c0e2c0ea846fab12cbd5c70a1d336689325973" },
{ 400004, "07b68b28622969c3df1987d0d5c6259cedf661f277039662e817051384c9b5af" },
{ 444444, "b3dd057a72e415861db116f9f7e49c3e9417e29614bf4962fe4f90e4632d0cef" },
{ 500000, "30138ff16e9925fe7a8d2db702cf52da2822c614066c3d41d6bcbb704a47eeeb" },
{ 555555, "b8bca0bc95a995f60e6e70d3d6d5efde291c4eb7a7ce4a76b126b47354ce74ef" },
{ 600000, "bea84c3cde5c6c47ea739e33e09e39b672c33acae434d34ccc5bf1d8177fe29c" },
{ 620000, "aff4cbc82e142ef03e4e4a9953034071c21752f9a7c00e5b385aa0cac0eeb9bb" },
{ 640000, "63f664a39a9bc958fa61e5088862ab117f1f513fda16584f4ec7031087661fce" },
{ 656000, "35b04e2217494c7b818eccad9b7f7fadc3d8d23a8e216dfcff444691fd57fc0f" },
{ 656114, "6c5ff7712c1bd5716679969b3903a6711b258202e78a729907c2af0eb299214c" },
{ 657001, "68cc01388e1e4a1b4a8fc885e911f0c09dbea594183111047d926fad41669a09" },
{ 657002, "29952d93e156602008c03070089d6ba6375e770dda5d31603d7493eec23e8618" },
{ 657025, "b654644cc363120a88f15e044cbe04935f7a0e347a72901a46d1db88348a7392" },
{ 690000, "294f9c92ec345d23543ce7dfb7d2487cb6d3b3c64e6d0158b165bf9f530aef30" }
};

}
// { 800000, "" }
