import imaplib
msrvr = imaplib.IMAP4_SSL \
        ('imap.gmail.com',993)
msrvr.login("virendra@fabfresh.in","pratap789")
stat,cnt = msrvr.select('Inbox',"UNSEEN")

stat, data = msrvr.fetch \
             (cnt[0],\
             '(UID BODY[TEXT])')

split_page =  data[0][1].split("Sub-Total Amount", 1)
split_name = split_page[0]



a = split_name.find("Customer Name:")
b = split_name.find("Mobile")
c = split_name.find("Sub-Total")
d = split_name.find("Address")
name = split_name[a+15:b-2]
mob = split_name[b+15:b+25]
add = split_name[d+8:c]
#print name,mob,add

dic={"Customer_name":name,"Mobile no.":mob,"Address":add}
print dic
msrvr.close()
msrvr.logout()
