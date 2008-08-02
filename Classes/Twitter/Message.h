#import <UIKit/UIKit.h>
#import "User.h"
#import "sqlite3.h"

typedef enum {
    MSG_TYPE_FRIENDS = 0,
    MSG_TYPE_REPLIES,
    MSG_TYPE_MESSAGES,
} MessageType;

#define IMAGE_PADDING       10
#define H_MARGIN            10
#define INDICATOR_WIDTH     20
#define DETAIL_BUTTON_WIDTH 19
#define IMAGE_WIDTH         48

#define TOP                 16
#define LEFT                (IMAGE_PADDING * 2 + IMAGE_WIDTH)
#define CELL_WIDTH          (320 - INDICATOR_WIDTH - LEFT)

@interface Message : NSObject
{
	sqlite_int64    messageId;
	User*           user;
	NSString*       text;
    NSString*       createdAt;

    BOOL            unread;
    MessageType     type;
    CGRect          textBounds;
    CGFloat         cellHeight;
    
    UITableViewCellAccessoryType accessoryType;
}

@property (nonatomic, assign) sqlite_int64  messageId;
@property (nonatomic, assign) User*         user;
@property (nonatomic, copy)   NSString*     text;
@property (nonatomic, copy)   NSString*     createdAt;

@property (nonatomic, assign) BOOL          unread;
@property (nonatomic, assign) CGRect        textBounds;
@property (nonatomic, assign) CGFloat       cellHeight;
@property (nonatomic, assign) UITableViewCellAccessoryType accessoryType;

+ (Message*)messageWithJsonDictionary:(NSDictionary*)dic type:(MessageType)type storeDB:(BOOL)storeDB;
+ (Message*)initWithDB:(sqlite3_stmt*)statement type:(MessageType)type;
- (Message*)initWithJsonDictionary:(NSDictionary*)dic type:(MessageType)type storeDB:(BOOL)storeDB;

@end
