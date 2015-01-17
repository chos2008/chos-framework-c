/**
 * HTTP message 遵照由RFC 822 [9]规范格式定义来传输实
 * 体(消息负载).
 * <p>
 * generic-message = start-line
 *                   *(message-headerCRLF)
 *                   CRLF
 *                   [message-body]
 *
 * start-line = Request-Line|Status-Line
 * Request-Line =
 * Status-Line =
 *
 * message-header = field-name":"[field-value]
 * field-name = token
 * field-value = *(field-content|LWS)
 * field-content = <OCTET, *TEXT, token, separators, quoted-string的组成>
 *
 * message-body = entity-body|<按每个Transfer-Encoding编码的entity-body>
 *
 * entity-body  = Content-Encoding(Content-Type(data))
 */
typedef struct HTTPMESSAGE
{

} HTTPMESSAGE;

/*
 * Request         = Request-Line
 *                   *((general-header|request-header|entity-header)CRLF)
 *                   CRLF
 *                   [message-body]
 *
 * Request-Line    = Method SP Request-URI SP HTTP-VersionCRLF
 *
 * Method          = "OPTIONS"|"GET"|"HEAD"|"POST"|"PUT"|"DELETE"|"TRACE"|"CONNECT"|extension-method
 * extension-method= token
 *
 * SP              = SPACE
 * Request-URI     = "*"|absoluteURI|abs_path|authority
 *
 * HTTP-Version    = HTTP"/"Version-number
 * Version-number  = 1.0|1.1|1.2
 *
 *
 * general-header  = Cache-Control|Connection|Date|Pragma|Trailer|Transfer-Encoding|Upgrade|Via|Warning
 *
 * request-header  = Accept|Accept-Charset|Accept-Encoding|Accept-Language|Authorization|Expect|From|Host
 *                   |If-Match|If-Modified-Since|If-None-Match|If-Range|If-Unmodified-Since|Max-Forwards
 *                   |Proxy-Authorization|Range|Referer|TE|User-Agent
 */

/*
 * 在HTTP报文(请求)消息结构中, 暂时规定用3个比特为(bit)来表示
 * <p>
 * +-----
 */
#define GET      = 0x00
#define POST     = 0x01
#define OPTIONS  = 0x02
#define HEAD     = 0x03
#define PUT      = 0x04
#define DELETE   = 0x05
#define TRACE    = 0x06
#define CONNECT  = 0x07
typedef struct HTTPREQUEST
{

} HTTPREQUEST;

/*
 * Response        = Status-Line
 *                   *((general-header|response-header|entity-header)CRLF)
 *                   CRLF
 *                   [message-body]
 * Status-Line     = HTTP-Version SP Status-Code SP Reason-PhraseCRLF
 * HTTP-Version    = HTTP"/"Version-number
 * Version-number  = 1.0|1.1|1.2
 * SP              = SPACE
 * Status-Code     = "100"|"101"
 *                   |"200"|"201"|"202"|"203"|"204"|"205"|"206"
 *                   |"300"|"301"|"302"|"303"|"304"|"305"|"307"
 *                   |"400"|"401"|"402"|"403"|"404"|"405"|"406"|"407"|"408"|"409"|"410"|"411"|"412"|"413"|"414"|"415"|"416"|"417"
 *                   |"500"|"501"|"502"|"503"|"504"|"505"
 *                   |extension-code
 * extension-code  = 3DIGIT
 * Reason-Phrase   = *<TEXT, 除CR, LF外>
 *
 * general-header  = Cache-Control|Connection|Date|Pragma|Trailer|Transfer-Encoding|Upgrade|Via|Warning
 *
 * response-header = Accept-Ranges|Age|ETag|Location|Proxy-Authenticate|Retry-After|Server|Vary|WWW-Authenticate
 *
 * entity-header   = Allow|Content-Encoding|Content-Language|Content-Length|Content-MD5|Content-Range|Content-Type|Expires|Last-Modified|extension-header
 * extension-header= message-header
 *
 * message-body    = entity-body|<按每个Transfer-Encoding编码的entity-body>
 *
 * entity-body  = Content-Encoding(Content-Type(data))
 */
typedef struct HTTPRESPONSE
{

} HTTPRESPONSE;
