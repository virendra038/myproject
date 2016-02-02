import time
from selenium import webdriver

driver = webdriver.Firefox()
driver.get('http://192.168.1.14:80/')
i=1
while i==1:
    time.sleep(3)
    driver.refresh()
    time.sleep(2)


driver.close()
