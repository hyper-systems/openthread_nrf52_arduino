/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 * @file - This file contains ECDH P256 test vectors.
 */

#ifndef _ECDH_P256_TEST_VECTORS_H_
#define _ECDH_P256_TEST_VECTORS_H_

typedef struct ECDH_P256_test_vector
{
    uint8_t * local_pvt_key;
    const size_t local_pvt_key_length;
    uint8_t * remote_pub_key;
    const size_t remote_pub_key_length;
    const uint8_t * shared_secret;
    const size_t shared_secret_length;

} ECDH_P256_test_vector;

uint8_t local_private_key1[] = { 0x7d, 0x7d, 0xc5, 0xf7, 0x1e, 0xb2, 0x9d, 0xda, 0xf8, 0x0d, 0x62, 0x14, 0x63, 0x2e, 0xea, 0xe0,
                                 0x3d, 0x90, 0x58, 0xaf, 0x1f, 0xb6, 0xd2, 0x2e, 0xd8, 0x0b, 0xad, 0xb6, 0x2b, 0xc1, 0xa5, 0x34 };

uint8_t remote_public_key1[] = { 0x04, 0x70, 0x0c, 0x48, 0xf7, 0x7f, 0x56, 0x58, 0x4c, 0x5c, 0xc6, 0x32, 0xca,
                                 0x65, 0x64, 0x0d, 0xb9, 0x1b, 0x6b, 0xac, 0xce, 0x3a, 0x4d, 0xf6, 0xb4, 0x2c,
                                 0xe7, 0xcc, 0x83, 0x88, 0x33, 0xd2, 0x87, 0xdb, 0x71, 0xe5, 0x09, 0xe3, 0xfd,
                                 0x9b, 0x06, 0x0d, 0xdb, 0x20, 0xba, 0x5c, 0x51, 0xdc, 0xc5, 0x94, 0x8d, 0x46,
                                 0xfb, 0xf6, 0x40, 0xdf, 0xe0, 0x44, 0x17, 0x82, 0xca, 0xb8, 0x5f, 0xa4, 0xac };

const uint8_t shared_secret1[] = { 0x46, 0xfc, 0x62, 0x10, 0x64, 0x20, 0xff, 0x01, 0x2e, 0x54, 0xa4, 0x34, 0xfb, 0xdd, 0x2d, 0x25,
                                   0xcc, 0xc5, 0x85, 0x20, 0x60, 0x56, 0x1e, 0x68, 0x04, 0x0d, 0xd7, 0x77, 0x89, 0x97, 0xbd, 0x7b };

ECDH_P256_test_vector ecdh_v1 = { .local_pvt_key         = local_private_key1,
                                  .local_pvt_key_length  = sizeof(local_private_key1),
                                  .remote_pub_key        = remote_public_key1,
                                  .remote_pub_key_length = sizeof(remote_public_key1),
                                  .shared_secret         = shared_secret1,
                                  .shared_secret_length  = sizeof(shared_secret1) };

uint8_t local_private_key2[] = { 0x00, 0xf5, 0xf8, 0xe0, 0x17, 0x46, 0x10, 0xa6, 0x61, 0x27, 0x79,
                                 0x79, 0xb5, 0x8c, 0xe5, 0xc9, 0x0f, 0xee, 0x6c, 0x9b, 0x3b, 0xb3,
                                 0x46, 0xa9, 0x0a, 0x71, 0x96, 0x25, 0x5e, 0x40, 0xb1, 0x32, 0xef };

uint8_t remote_public_key2[] = { 0x04, 0x33, 0xe8, 0x20, 0x92, 0xa0, 0xf1, 0xfb, 0x38, 0xf5, 0x64, 0x9d, 0x58,
                                 0x67, 0xfb, 0xa2, 0x8b, 0x50, 0x31, 0x72, 0xb7, 0x03, 0x55, 0x74, 0xbf, 0x8e,
                                 0x5b, 0x71, 0x00, 0xa3, 0x05, 0x27, 0x92, 0xf2, 0xcf, 0x6b, 0x60, 0x1e, 0x0a,
                                 0x05, 0x94, 0x5e, 0x33, 0x55, 0x50, 0xbf, 0x64, 0x8d, 0x78, 0x2f, 0x46, 0x18,
                                 0x6c, 0x77, 0x2c, 0x0f, 0x20, 0xd3, 0xcd, 0x0d, 0x6b, 0x8c, 0xa1, 0x4b, 0x2f };

const uint8_t shared_secret2[] = { 0x66, 0x4e, 0x45, 0xd5, 0xbb, 0xa4, 0xac, 0x93, 0x1c, 0xd6, 0x5d, 0x52, 0x01, 0x7e, 0x4b, 0xe9,
                                   0xb1, 0x9a, 0x51, 0x5f, 0x66, 0x9b, 0xea, 0x47, 0x03, 0x54, 0x2a, 0x2c, 0x52, 0x5c, 0xd3, 0xd3 };

ECDH_P256_test_vector ecdh_v2 = { .local_pvt_key         = local_private_key2,
                                  .local_pvt_key_length  = sizeof(local_private_key2),
                                  .remote_pub_key        = remote_public_key2,
                                  .remote_pub_key_length = sizeof(remote_public_key2),
                                  .shared_secret         = shared_secret2,
                                  .shared_secret_length  = sizeof(shared_secret2) };

uint8_t local_private_key3[] = { 0x7A, 0xE6, 0x7A, 0xFC, 0xF2, 0x50, 0x5C, 0x12, 0xB7, 0x60, 0x0F, 0xA2, 0x25, 0x85, 0x9A, 0xFE,
                                 0x36, 0xFA, 0x01, 0xE7, 0xB0, 0x78, 0x9C, 0xF5, 0x9B, 0x06, 0xA1, 0xC9, 0xB8, 0xEF, 0x90, 0xD2 };

uint8_t remote_public_key3[] = { 0x04, 0x19, 0x6C, 0x32, 0xA9, 0x90, 0x1B, 0xDC, 0x81, 0x70, 0x28, 0x0C, 0x78,
                                 0x94, 0x71, 0x32, 0xB9, 0x2C, 0x9A, 0x7B, 0x8D, 0x4F, 0x59, 0x7A, 0x18, 0x33,
                                 0x71, 0x25, 0x45, 0x8C, 0xCF, 0x92, 0x56, 0x1B, 0xA3, 0x80, 0x9E, 0xC1, 0xB9,
                                 0x66, 0x8A, 0x29, 0x03, 0x68, 0x66, 0xE6, 0xD8, 0x45, 0x89, 0x11, 0x01, 0x3E,
                                 0x2E, 0x78, 0xF9, 0x29, 0x6E, 0x86, 0xD6, 0x81, 0x7F, 0x7A, 0xE6, 0xF3, 0x09 };

const uint8_t shared_secret3[] = { 0x00, 0x13, 0xB5, 0x76, 0xC6, 0xC0, 0x27, 0x02, 0xB1, 0xB6, 0x6C, 0x67, 0xFA, 0xB4, 0x6D, 0xA8,
                                   0x54, 0x88, 0x0A, 0x39, 0xD7, 0x5F, 0xA7, 0x44, 0x64, 0x1F, 0xFA, 0x61, 0x11, 0x82, 0x3A, 0x4E };

ECDH_P256_test_vector ecdh_v3 = { .local_pvt_key         = local_private_key3,
                                  .local_pvt_key_length  = sizeof(local_private_key3),
                                  .remote_pub_key        = remote_public_key3,
                                  .remote_pub_key_length = sizeof(remote_public_key2),
                                  .shared_secret         = shared_secret3,
                                  .shared_secret_length  = sizeof(shared_secret3) };

ECDH_P256_test_vector ecdh_test_vectors[] = { ecdh_v1, ecdh_v2, ecdh_v3 };
#endif
