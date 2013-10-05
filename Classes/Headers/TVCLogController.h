/* ********************************************************************* 

 Copyright (c) 2008 - 2010 Satoshi Nakagawa <psychs AT limechat DOT net>
 Copyright (c) 2010 — 2013 Codeux Software & respective contributors.
        Please see Contributors.rtfd and Acknowledgements.rtfd

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the IRC Client & Codeux Software nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

 *********************************************************************** */

#import "IRCApplication.h"

@interface TVCLogController : NSObject
@property (nonatomic, nweak) IRCClient *client;
@property (nonatomic, nweak) IRCChannel *channel;
@property (nonatomic, strong) TVCLogView *view;
@property (nonatomic, strong) TVCLogPolicy *policy;
@property (nonatomic, strong) TVCLogScriptEventSink *sink;
@property (nonatomic, strong) TVCWebViewAutoScroll *autoScroller;
@property (nonatomic, strong) TVCLogControllerHistoricLogFile *historicLogFile;
@property (nonatomic, assign) BOOL isLoaded;
@property (nonatomic, assign) BOOL needsLimitNumberOfLines;
@property (nonatomic, assign) NSInteger activeLineCount;
@property (nonatomic, assign) NSInteger maximumLineCount;
@property (nonatomic, strong) NSString *lastVisitedHighlight;
@property (nonatomic, strong) NSMutableArray *highlightedLineNumbers;

@property (assign) BOOL reloadingBacklog;
@property (assign) BOOL reloadingHistory;
@property (strong) NSMutableArray *pendingPrintOperations; // Plugins… do not try and modify this array. EVER!

- (void)setUp;
- (void)notifyDidBecomeVisible;

- (void)preferencesChanged;
- (void)terminate;

- (void)nextHighlight;
- (void)previousHighlight;

- (BOOL)highlightAvailable:(BOOL)previous;

- (DOMDocument *)mainFrameDocument;

- (void)moveToTop;
- (void)moveToBottom;

- (NSString *)topicValue;
- (void)setTopic:(NSString *)topic;

- (BOOL)inlineImagesEnabledForView;

- (void)mark;
- (void)unmark;
- (void)goToMark;

- (void)clear;

- (void)reloadTheme;

- (void)changeTextSize:(BOOL)bigger;

- (void)print:(TVCLogLine *)logLine;
- (void)print:(TVCLogLine *)logLine completionBlock:(void(^)(BOOL highlighted))completionBlock;

- (NSString *)renderedBodyForTranscriptLog:(TVCLogLine *)line;

- (void)logViewOnDoubleClick:(NSString *)e;

- (void)executeScriptCommand:(NSString *)command withArguments:(NSArray *)args; // Defaults to onQueue YES
- (void)executeScriptCommand:(NSString *)command withArguments:(NSArray *)args onQueue:(BOOL)onQueue;
@end