#import <UIKit/UIKit.h>
#import "TFConnection.h"
#import "Message.h"

typedef enum {
    TWITTER_REQUEST_TIMELINE,
    TWITTER_REQUEST_FAVORITE,
    TWITTER_REQUEST_UPDATE,
    TWITTER_REQUEST_DESTROY,
} RequestType;

@interface TwitterClient : TFConnection
{
    RequestType request;
}

@property (nonatomic, readonly) RequestType request;

- (void)get:(MessageType)type params:(NSDictionary*)params;
- (void)post:(NSString*)tweet;
- (void)destroy:(Message*)message;
@end
