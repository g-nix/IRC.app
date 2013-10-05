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

@interface TDCListDialog : NSWindowController
@property (nonatomic, uweak) id delegate;
@property (nonatomic, nweak) IRCClient *client;
@property (nonatomic, nweak) NSButton *updateButton;
@property (nonatomic, nweak) NSSearchField *searchField;
@property (nonatomic, nweak) NSTextField *networkNameField;
@property (nonatomic, nweak) TVCListView *channelListTable;
@property (nonatomic, strong) NSMutableArray *unfilteredList;
@property (nonatomic, strong) NSMutableArray *filteredList;
@property (nonatomic, assign) NSComparisonResult sortOrder;
@property (nonatomic, assign) NSInteger sortKey;

- (void)start;
- (void)show;
- (void)close;
- (void)clear;

- (void)addChannel:(NSString *)channel count:(NSInteger)count topic:(NSString *)topic;

- (void)onClose:(id)sender;

- (void)onUpdate:(id)sender;
- (void)onJoinChannels:(id)sender;
- (void)onSearchFieldChange:(id)sender;
@end

@interface NSObject (TXListDialogDelegate)
- (void)listDialogOnUpdate:(TDCListDialog *)sender;
- (void)listDialogOnJoin:(TDCListDialog *)sender channel:(NSString *)channel;
- (void)listDialogWillClose:(TDCListDialog *)sender;
@end