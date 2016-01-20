import imaplib
msrvr = imaplib.IMAP4_SSL \
        ('imap.gmail.com',993)
msrvr.login("virendra@fabfresh.in","pratap789")
stat,cnt = msrvr.select('Inbox',"UNSEEN")

stat, data = msrvr.fetch \
             (cnt[0],\
             '(UID BODY[TEXT])')

split_page =  data[0][1].split("Sub-Total Amount", 1)
split_page = split_page[0]
split_page1 = split_page.split("You have received an order on Bro4u.com. Below are the details:")
split_page = split_page1[1]
split_name = split_page.split("Order Placed On")
split_name = split_name[0]
#print split_name
split_add = split_page.split("Address:")
add = split_add[1]
#print split_add


a = split_name.find("Customer Name:")
b = split_name.find("Mobile")
name = split_name[a+15:b-2]
mob = split_name[b+15:b+25]
#print name,mob,add

dic={"Customer_name":name,"Mobile no.":mob,"Address":add}
print dic
msrvr.close()
msrvr.logout()
