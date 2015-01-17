/*
 *
 *
 */

#include <string>
using namespace std;
#include "Hashtable.h"

/**
 *
 *
 */
#if ! defined SIP_USER_INFO
#define SIP_USER_INFO

/**
 * {@link UserInfo} represents the "userinfo" defines in the specification rfc 3261
 * for SIP(Session Initiation Protocol) 
 *
 * The "userinfo" is a part of SIP and SIPS URI(SIP and SIPS Uniform Resource 
 * Indicators). The "userinfo" of a URI consists of this user field, the password 
 * field, and the @ sign following them.  The userinfo part of a URI is optional 
 * and MAY be absent when the destination host does not have a notion of users or when the
 * host itself is the resource being identified.  If the @ sign is
 * present in a SIP or SIPS URI, the user field MUST NOT be empty.
 *
 * If the host being addressed can process telephone numbers, for
 * instance, an Internet telephony gateway, a telephone-
 * subscriber field defined in RFC 2806 [9] MAY be used to
 * populate the user field.  There are special escaping rules for
 * encoding telephone-subscriber fields in SIP and SIPS URIs
 * described in Section 19.1.2.
 */
class UserInfo {

private:

	string user;

	string password;

public:

	UserInfo(string user);

	UserInfo(string user, string password);

};

#endif;

/**
 * The "sip:" and "sips:" schemes follow the guidelines in RFC 2396 [5].
 * They use a form similar to the mailto URL, allowing the specification
 * of SIP request-header fields and the SIP message-body.  This makes it
 * possible to specify the subject, media type, or urgency of sessions
 * initiated by using a URI on a web page or in an email message.  The
 * formal syntax for a SIP or SIPS URI is presented in Section 25.  Its
 * general form, in the case of a SIP URI, is:
 *
 *    sip:user:password@host:port;uri-parameters?headers
 *
 * The format for a SIPS URI is the same, except that the scheme is
 * "sips" instead of sip.
 *
 * Example SIP and SIPS URIs
 *
 * sip:alice@atlanta.com
 * sip:alice:secretword@atlanta.com;transport=tcp
 * sips:alice@atlanta.com?subject=project%20x&priority=urgent
 * sip:+1-212-555-1212:1234@gateway.com;user=phone
 * sips:1212@gateway.com
 * sip:alice@192.0.2.4
 * sip:atlanta.com;method=REGISTER?to=alice%40atlanta.com
 * sip:alice;day=tuesday@atlanta.com
 *
 * The last sample URI above has a user field value of
 * "alice;day=tuesday".  The escaping rules defined above allow a
 * semicolon to appear unescaped in this field.  For the purposes of
 * this protocol, the field is opaque.  The structure of that value is
 * only useful to the SIP element responsible for the resource.
 */
#if ! defined SIP_URI
#define SIP_URI

class URI {

private:

	string user;

	string password;

	string host;

	string port;

	Hashtable parameters;

	Hashtable headers;

public:

	URI(string host);

	URI(string host, string port);

	URI(string host, string port, Hashtable parameters);

	URI(string host, string port, Hashtable parameters, Hashtable headers);

	URI(UserInfo userinfo, string host);

	URI(UserInfo userinfo, string host, string port);

	URI(UserInfo userinfo, string host, string port, Hashtable parameters, Hashtable headers);
};

#endif;