inherit ROOM;

string *members = ({ });

void create()
{
        set("short", "�ѯ���w�Ĥ@�h");
        set("long", @long
�o�y���q�J��������N�O�ǻ������j�ѯ��ҫسy���u�ѯ���v�C
�ѩ�ѯ����O���v�T�A�o�y�������q�쯫�ҨC�Ӧa��A�Ӳ{�b�Ҧb
����m�O�ѯ��𪺲Ĥ@�h�A���W�ӱ�i�H�q�D�ĤG�h�C�A�V��n���
�h�A�o�{�@���Z�����ΡF�F�n��h�O���㤧�ΡC�A���n���A�|��F��
�Ҫ��|ĳ�j�U�M�D�㤧�ΡC

long);
        set("exits", ([
  "north" : __DIR__"entrance",
    "up" : __DIR__"ladd-2",
  "southwest" : __DIR__"room_wp.c",
  "southeast" : __DIR__"room_eq.c",
  "south" : __DIR__"boardroom.c",
  "northeastup" : __DIR__"vip_room.c",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}
/*
int valid_leave(object me, string dir)
{
        if( dir == "northeastup" && !wizardp(me) )
        {
                if( load_object(__DIR__"vip_room.c") )
                {
                          if( member_array(getuid(me), members) != -1 || getuid(me) == "deaon" )
                        {
                                tell_room(this_object(), me->name()+"�����κ������S..\n", ({ me }));
                                me->move(__DIR__"vip_room.c");
                                tell_room(load_object(__DIR__"vip_room.c"), me->name()+"�q���U�����W�ɦܦ��a�C\n", ({ me }));
                                return 1;
                        }
                        else return notify_fail("�A�S���o�� tear ���\\�i�L�k�i�J�C\n");
                }
                else return notify_fail("��V�X�f�ж����~�C\n");
        }
        else return ::valid_leave(me, dir);
}

void init()
{
         if( getuid(this_player()) == "deaon" )
        {
                add_action("do_control", "control");
        }
}

int do_control(string arg)
{
        if( !arg ) return notify_fail("�榡: control <�H�W>\n");
        if( member_array(arg, members) != -1 )
        {
                members -= ({ arg });
                write("�R���i�i�X�H�� "+arg+"�C\n");
                return 1;
        }
        else
        {
                members += ({ arg });
                write("�W�[�i�i�X�H�� "+arg+"�C\n");
                return 1;
        }
        return notify_fail("�榡: control <�H�W>\n");
}
string *query_members() { return members; }
*/
