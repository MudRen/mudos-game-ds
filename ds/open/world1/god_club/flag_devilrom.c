inherit ROOM;

string *members = ({ });
void create()
{
        set("short", "�]��");
        set("long", @long
�]�ɡA�O�ӥR���۸o�c���`�W�A��O�Ѧa�ƻa�U�c�������E���B
�A�H�B���i�ݨ������ۤ����W�ä㪺�S�R�^�y�H�εL�Ƥd�_�ʩǪ���
�ƨƪ��A�ϤH�ݨ쳣���T���F�ӧNŸ�A�ڻ��̭��õۻ��j�ɥN�E�ת�
���@�Z�\�A�����L�ƫi�̶i�ӧ�M�A�ܤ����L�@���٪������ǥX�C

long);
        set("exits", ([
  "northwest" : __DIR__"ladd-2",
  "northeastup" : __DIR__"vip2_room.c",
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
                if( load_object(__DIR__"vip2_room.c") )
                {
                        if( member_array(getuid(me), members) != -1 || getuid(me) == "exri" )
                        {
                                tell_room(this_object(), me->name()+"�C�n����F�X�y�G�y�A���v�]�C�C�������F�E�E�E\n", ({ me }));
                                me->move(__DIR__"vip2_room.c");
                                tell_room(load_object(__DIR__"vip2_room.c"), me->name()+"�q���U�����W�ɦܦ��a�C\n", ({ me }));
                                return 1;
                        }
                        else return notify_fail("�A�S���o�� exri ���\\�i�L�k�i�J�C\n");
                }
                else return notify_fail("��V�X�f�ж����~�C\n");
        }
        else return ::valid_leave(me, dir);
}

void init()
{
        if( getuid(this_player()) == "exri" )
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
