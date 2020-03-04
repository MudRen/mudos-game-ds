inherit ITEM;
void create()
{
        set_name("���֯�",({"alchemy paper","paper"}) );
        set_weight(100);
        set("long",@long
�o�O�@���ݯʤ��������֯ȡA�W�Y�ҮѤ�r���ٲM���i�G�A���G���Z�L
�y�ǵۦW���u���A�į󥻡v�����i�A�u���A�į󥻡v���@�Ҥ��s�Ī��_�ѡA
�䤺�e�դj��`�C���i�W�Y�g�۬O�򥻪��m�Ī���l�A�L�ө����A�@���Ѧr
���H����\Ū(read)�F�ѡC
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",300);
        }
        setup();
}

void init()
{
        add_action("do_read","read");
        add_action("do_pharmacy","pharmacy");
}

int do_read(string arg)
{
        object me;
        me=this_player();
        if(!arg) return 0;
        if(!this_object()->id(arg) ) return 0;
        if(me->query_skill("literate") <10) 
                return notify_fail("�A��Ū���Ѧr�����A�ݤ����W�Y�g�����e�C\n");
        write(@LONG
�E��^�R�� (nine pill)
���򥻥i�m�����A��t��H�u�K�u��v�B�u�ӳ��v�G���հt�Y���C
�M�F�� (green pill)
���򥻥i�m�����A��t��H�u�K�u��v�B�u�ѤH�ڡv�G���հt�Y���C
�G�������� (light pill):
���򥻥i�m�����A��t��ݥH�u�K�u��v�B�u�ӳ��v�Ρu�ѤH�ڡv�հt�Y���C

�հt���O�G(pharmacy + ���ĦW��)
LONG
);
        return 1;
}

int do_pharmacy(string arg)
{
        object me,mixture,linn,roxb,benth;
        me=this_player();
        if(!arg ) return notify_fail("�A�n�հt���@�Ӱt��H\n");
        switch(arg)
        {
        case "nine pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("�A���W�S���u�K�u��v�A�L�k�հt�E��^�R���C\n");
        if(!objectp(roxb=present("phytolacca acinosa roxb",me)) )
                return notify_fail("�A���W�S���u�ӳ��v�A�L�k�հt�E��^�R���C\n");
        destruct(linn);
        destruct(roxb);
        mixture=new(__DIR__"mixture1");
        mixture->move(me);
        message_vision("$N�̷ӯ��A�į󥻩Ҽg�A�N���W�ħ��հt�X�@�Ӱt��C\n",me);
        break;

        case "light pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("�A���W�S���u�K�u��v�A�L�k�հt�G�����夦�C\n");
        if(!objectp(roxb=present("phytolacca acinosa roxb",me)) )
                return notify_fail("�A���W�S���u�ӳ��v�A�L�k�հt�G�����夦�C\n");
        if(!objectp(benth=present("millettia nitida benth",me)) )
                return notify_fail("�A���W�S���u�ѤH�ڡv�A�L�k�հt�G�����夦�C\n");
        destruct(linn);
        destruct(roxb);
        destruct(benth);
        mixture=new(__DIR__"mixture2");
        mixture->move(me);
        message_vision("$N�̷ӯ��A�į󥻩Ҽg�A�N���W�ħ��հt�X�@�Ӱt��C\n",me);


        case "green pill":
        if(!objectp(linn=present("adiantum flabellulatum linn",me)) )
                return notify_fail("�A���W�S���u�K�u��v�A�L�k�հt�M�F���C\n");
        if(!objectp(benth=present("millettia nitida benth",me)) )
                return notify_fail("�A���W�S���u�ѤH�ڡv�A�L�k�հt�M�F���C\n");
        destruct(linn);
        destruct(roxb);
        mixture=new(__DIR__"mixture3");
        mixture->move(me);
        message_vision("$N�̷ӯ��A�į󥻩Ҽg�A�N���W�ħ��հt�X�@�Ӱt��C\n",me);
        break;

        break;

        default:
        return notify_fail("���o�ذt��ܡH�H\n");
        break;
        }
        return 1;
}


