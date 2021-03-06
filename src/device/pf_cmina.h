/*********************************************************************
 *        _       _         _
 *  _ __ | |_  _ | |  __ _ | |__   ___
 * | '__|| __|(_)| | / _` || '_ \ / __|
 * | |   | |_  _ | || (_| || |_) |\__ \
 * |_|    \__|(_)|_| \__,_||_.__/ |___/
 *
 * www.rt-labs.com
 * Copyright 2018 rt-labs AB, Sweden.
 *
 * This software is dual-licensed under GPLv3 and a commercial
 * license. See the file LICENSE.md distributed with this software for
 * full license information.
 ********************************************************************/

#ifndef PF_CMINA_H
#define PF_CMINA_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Initialize the CMINA component.
 * @return  0  if the operation succeeded.
 *          -1 if an error occurred.
 */
int pf_cmina_init(void);

/**
 * Show the CMINA status.
 */
void pf_cmina_show(void);

/**
 * Retrieve the configured station name of the device.
 * @param pp_station_name  Out:  The station name.
 * @return  0  if the operation succeeded.
 *          -1 if an error occurred.
 */
int pf_cmina_get_station_name(
   const char              **pp_station_name);

/**
 * Retrieve the configured IP address of the device.
 * @param p_ipaddr         Out:  The ip_address.
 * @return  0  if the operation succeeded.
 *          -1 if an error occurred.
 */
int pf_cmina_get_ipaddr(
   os_ipaddr_t             *p_ipaddr);

/**
 * Handle the DCP set command.
 * @param opt              In:   The option key.
 * @param sub              In:   The sub-option key.
 * @param block_qualifier  In:   The block qualifier.
 * @param value_length     In:   The length of the data to set.
 * @param p_value          In:   The data to set.
 * @param p_block_error    Out:  The block error code, if any.
 * @return  0  if the operation succeeded.
 *          -1 if an error occurred.
 */
int pf_cmina_dcp_set_ind(
   uint8_t                 opt,
   uint8_t                 sub,
   uint16_t                block_qualifier,
   uint16_t                value_length,
   uint8_t                 *p_value,
   uint8_t                 *p_block_error);

/**
 * Commit changes to the IP-suite.
 *
 * This shall be done _after_ the answer to DCP set has been sent.
 */
void pf_cmina_dcp_set_commit(void);

/**
 * Handle the DCP get command.
 * @param opt              In:   The option key.
 * @param sub              In:   The sub-option key.
 * @param value_length     In:   The length of the pp_value buffer.
 *                         Out:  The length of the read data.
 * @param pp_value         Out:  The retrieved data.
 * @param p_block_error    Out:  The block error code, if any.
 * @return  0  if the operation succeeded.
 *          -1 if an error occurred.
 */
int pf_cmina_dcp_get_req(
   uint8_t                 opt,
   uint8_t                 sub,
   uint16_t                *p_value_length,
   uint8_t                 **pp_value,
   uint8_t                 *p_block_error);

#ifdef __cplusplus
}
#endif

#endif /* PF_CMINA_H */
