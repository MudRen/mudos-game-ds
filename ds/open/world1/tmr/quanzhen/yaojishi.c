// yaojishi.c �ľ���
// Winder Oct.10 1998

inherit ROOM;
int do_pullout(string arg);

void create()
{
        set("short", "�ľ���");
        set("long", @LONG
�o�̬O���u�Ш��ġB�t�Ī��a��C�o���ж����ӫܤj�A�u�O
�Q�e�ᥪ�k������d�Ľc������o�p�h�F�C���d�w�g�ܳ��¤F�A
���L�O�ΤW�n���n���I���찵�����A�ڻ��γo�ؤ���������d�l
�Ψ��x�êF�褣�|�D�γE�C���d�W�����ө�P(drawer)�C
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"xianzhentang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/zhangyao" : 1,
        ]));

        set("item_desc", ([
        "drawer": "�@�ө�P�A�����D�O�]���ʤ��٬O�����]�A�S���W��C\n"
        ]) );

        set("count",1);
	set("coor/x", -2810);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pullout","pullout");
}

int do_pullout(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "drawer" ) {
                return notify_fail("�A�n�Զ}����H\n");
        }

        if (query("count")>0) {
        message_vision("$N�X�۴x�ĹD����L���h�A���֦a���P�Զ}�A�̭��n��������F��A\n",this_player());
        message_vision("�٨S�ӱo�άݡA�x�ĹD���S��L���ӡC�u�~�o$N�@���_��P�̪��F��\n", this_player());
        message_vision("��i�h�̡A�M��˧@���Y�����d�����A���X�@�ƭY�L��ƪ��ˤl�C��\n",this_player());
        message_vision("���A�x�ĹD���~�M�S�oı�A$N���X�F�@�f��A��L�d�������F�^�ӡC\n",this_player());
        add("count",-1);
        ob=new("/clone/medicine/vegetable/tianqi");
        ob->move(me);
        }
        else {
        message_vision("$N�X�۴x�ĹD����L���h�A���֦a���P�Զ}�A�̭��ŪŦp�]�A�쥻�b\n",this_player());
        message_vision("�̭����F��n���w�g�Q�H�����F�C\n", this_player());
        }

        return 1;
}