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

@implementation TDCInviteSheet

- (id)init
{
	if ((self = [super init])) {
		[NSBundle loadNibNamed:@"TDCInviteSheet" owner:self];
	}

	return self;
}

- (void)startWithChannels:(NSArray *)channels
{
	NSString *target = nil;
	
	if (self.nicknames.count == 1) {
		target = [self.nicknames safeObjectAtIndex:0];
	} else if (self.nicknames.count == 2) {
		NSString *firstn = [self.nicknames safeObjectAtIndex:0];
		NSString *second = [self.nicknames safeObjectAtIndex:1];
		
		target = TXTFLS(@"InviteSheetTwoPeopleSelected", firstn, second);
	} else {
		target = TXTFLS(@"InviteSheetMultiplePeopleSelected", self.nicknames.count);
	}
	
	self.headerTitleField.stringValue = TXTFLS(@"InviteSheetTargetDescription", target);
	
	for (NSString *s in channels) {
		[self.channelListPopup addItemWithTitle:s];
	}
	
	[self startSheet];
}

- (void)ok:(id)sender
{
	NSString *channelName = self.channelListPopup.selectedItem.title;
	
	if ([self.delegate respondsToSelector:@selector(inviteSheet:onSelectChannel:)]) {
		[self.delegate inviteSheet:self onSelectChannel:channelName];
	}

	[super ok:nil];
}

#pragma mark -
#pragma mark NSWindow Delegate

- (void)windowWillClose:(NSNotification *)note
{
	if ([self.delegate respondsToSelector:@selector(inviteSheetWillClose:)]) {
		[self.delegate inviteSheetWillClose:self];
	}
}

@end
