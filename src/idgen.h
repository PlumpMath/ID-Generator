/**
 * @file   idgen.h
 * @author Yen-Chin,Lee <coldnew.tw@gmail.com>
 * @date   Wed Dec 16 12:51:27 2009
 * @version 0.1.3
 * 
 * @brief  身份證字號產生的演算法
 * 
 * 
 */

#ifndef _ID_GEN_H
#define _ID_GEN_H

/**
 * @brief Generate the ID in Taiwan 
 *
 * @param country country
 * @param sex     sex
 *
 * @return        An ID in String type
 */
char * idgen(int country, int sex);

#endif /* _ID_GEN_H */

