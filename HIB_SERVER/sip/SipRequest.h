/*
 *
 *
 *
 */

#include "SipMessage.h"

#if ! defined SIP_REQUEST
#define SIP_REQUEST

/**
 * --------   -------------------------------------------------------------------------------
 * request              header fields
 * --------   -------------------------------------------------------------------------------
 * REGISTER             header field                    MUST               Comments
 *            ----------------------------------   ---------------   ------------------------
 *                      Request-URI                     MUST         The Request-URI names the domain of 
 *                                                                   the location service for which the 
 *                                                                   registration is meant (for example,
 *                                                                   "sip:chicago.com").  The "userinfo" 
 *                                                                   and "@" components of the SIP URI MUST 
 *                                                                   NOT be present.
 *                       To                             MUST         The To header field contains the address 
 *                                                                   of record whose registration is to be 
 *																	 created, queried, or modified.  The To
 *                                                                   header field and the Request-URI field 
 *																	 typically differ, as the former contains 
 *																	 a user name.  This address-of-record MUST
 *																	 be a SIP URI or SIPS URI.
 *                       From                           MUST
 *                       Call-ID                        MUST
 *                       CSeq                           MUST
 *                       Contact                        MAY
 */
class SipRequest : public SipMessage {

	
};

#endif;