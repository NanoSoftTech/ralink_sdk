/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2006, Ralink Technology, Inc.
 *
 * All rights reserved. Ralink's source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of Ralink Tech. Any attempt
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

 Module Name:
 acl_policy.h

Abstract:

Revision History:
Who         When            What
--------    ----------      ----------------------------------------------
Name        Date            Modification logs
Steven Liu  2007-01-23      Initial version
 */

#ifndef _ACL_POLICY_WANTED
#define _ACL_POLICY_WANTED

#include "policy.h"
#include "acl_ioctl.h"
#include "foe_fdb.h"

typedef struct {
    struct list_head List;
    enum AclRuleMethod Method; /* Allow,Deny */
    enum AclRuleOpt Operate; /* Add,Del */
    enum AclProtoType  Proto;  /* Any,Tcp,Udp */
    uint16_t RuleType; /* ioctl code */
    uint8_t Mac[6];
    uint32_t SipS; /* start of sip */
    uint32_t SipE; /* end of sip */
    uint32_t DipS; /* start of dip */
    uint32_t DipE; /* end of dip */
    uint16_t SpS; /* start of sport */
    uint16_t SpE; /* end of sport */
    uint16_t DpS; /* start of dport */
    uint16_t DpE; /* end of dport */
    uint16_t FoeTb; /* Foe Table Entry */
}AclPlcyNode;


/*
 * EXPORT FUNCTION
 */
uint32_t AclInsDflDeny(void);
uint32_t AclInsDflAllow(void);

uint32_t AclAddNode(AclPlcyNode *NewNode);
uint32_t AclDelNode(AclPlcyNode *NewNode);

uint32_t AclInsSmacDipDp(AclPlcyNode *node);
uint32_t AclInsSipDipDp(AclPlcyNode *node);

uint16_t PpeGetPreAclStr(void);
uint16_t PpeGetPreAclEnd(void);

uint32_t SyncAclTbl(void);
uint32_t AclCleanTbl(void);
uint32_t AclSetIpFragEntry(AclPlcyNode *node, enum FoeTblEE End);
uint32_t AclSetIpEntry(AclPlcyNode *node,  enum L3RuleDir Dir, enum FoeTblEE End);

void  PpeSetPreAclEbl(uint32_t AclEbl);
AclPlcyNode *AclExistNode(AclPlcyNode *NewNode);

#endif
