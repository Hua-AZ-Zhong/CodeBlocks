def printList( theList ):
    for each_item in theList:
        if isinstance(each_item, list):
            printList(each_item)
        else:
            print(each_item)
