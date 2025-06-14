//
// WebApiProjectCore.h
// Project 1.0
//
// Generated by ApiGenerator on Tuesday, November 21, 2023
//

#import <Foundation/Foundation.h>
#import "WebApiProjectError.h"

@class WebApiProjectManagerCore;

@protocol WebApiProjectManagerDelegate <NSObject>

@optional
-(void)WebApiProjectManager:(WebApiProjectManagerCore*)manager didPrepareRequest:(NSMutableURLRequest*)request;
-(void)WebApiProjectManager:(WebApiProjectManagerCore*)manager willPrepareRequest:(NSMutableURLRequest*)request;
-(void)WebApiProjectManager:(WebApiProjectManagerCore*)manager prepareJSONContent:(NSObject*)object withRequest:(NSMutableURLRequest*)request;

@end

@interface WebApiProjectManagerCore: NSObject{
	NSString *_baseURL;
}

@property(weak)id<WebApiProjectManagerDelegate> delegate;
@property(strong)NSString *baseURL;
@property(assign)int timeout;

-(NSData*)startReqest:(NSMutableURLRequest*)request withResponse:(NSHTTPURLResponse**)response withError:(NSError**)error;

-(void)removeCookies;

@end

@interface WebApiProjectApiBase : NSObject

@property(weak)WebApiProjectManagerCore *manager;

-(instancetype)initWithManager:(WebApiProjectManagerCore*)apiManager;

@end

extern NSString* WebApiProjectObjectToJson(id object);
extern NSDictionary* WebApiProjectPostToDictionary(NSString *value);
extern NSString* WebApiProjectDictionaryToPost(NSDictionary *value, NSString *name);
extern NSString* WebApiProjectArrayToPost(NSArray *value, NSString *name);
extern NSString* WebApiProjectObjectToPost(NSObject *value, NSString *name);
extern void WebApiProjectDictionaryToPostDataValue(NSObject *value, NSString *name, NSMutableData *content);
extern void WebApiProjectDictionaryToPostData(NSDictionary *value, NSString *name, NSMutableData *content);
extern void WebApiProjectArrayToPostData(NSArray *value, NSString *name, NSMutableData *content);
extern void WebApiProjectObjectToPostData(NSObject *value, NSString *name, NSMutableData *content);

extern NSString* WebApiProjectbase64EncodeData(NSData *objData);
extern NSData* WebApiProjectbase64DecodeString(NSString *strBase64);
extern NSString* WebApiProjectbase64EncodeString(NSString *strData);
