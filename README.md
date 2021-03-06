Description
--
SPConnector is designed to bring SharePoint whilst remaining lightweight.

It does not handle network connections itself and is designed to be flexible around this.

More SharePoint operations to come in the near future.

Getting Started
--
1. Copy the SPConnector folder into project
2. Add /usr/include/libxml2 to 'Header Search Paths'
3. Add -lxml2 to 'Other Linker Flags'

Example Usage
--
1. Copy the RequestSubclasses/AFSPURLConnectionOperation files into project

``` objective-c
NSURL *url = [NSURL URLWithString:@"http://sharepoint.example.com/"];
NSURLCredential *credential = [credentialWithUser:@"username"
                                         password:@"password"
                                      persistence:NSURLCredentialPersistenceNone];
self.ctx = [[SPContext alloc] initWithSiteURL:url];
[self.ctx setRequestSetupBlock:^(SPURLConnectionOperation *requestOperation) {
    // Called when a new request is allocated
    [requestOperation setAuthenticationChallengeBlock:^(NSURLConnection *connection, NSURLAuthenticationChallenge *challenge) {
        [[challenge sender] useCredential:credential forAuthenticationChallenge:challenge];
    }];
}];

[self.ctx getListCollection:^(NSArray *lists, NSError *error) {
    for (SPList *list in lists) {
        NSLog(@"%@", list.title);
    }
}];
```

License
--
SPConnector is available under the MIT license. See the LICENSE file for more info.