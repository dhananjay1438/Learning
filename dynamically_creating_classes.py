def main():
    num = int(input('Enter number of classes you want to create:'))
    classes_list = list()
    for i in range(num):
        class_name = f'class{i}'
        # Parameters: classname, bases (parent classes), data members
        classes_list.append(type(class_name, (), {'is_class': True}))


if __name__ == '__main__':
    main()
