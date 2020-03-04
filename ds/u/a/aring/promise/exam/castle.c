#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", YEL"�j��"HIY"����"NOR);
        set("long", @LONG
���g�������x����A�A�ש��F�ت��a�i�j���j�A�ǻ��������g�O�@
�W�j�N�ӱڪ������A�������D�����]�A�{�b�w�g�_�������]�̸��}���B
�B��H����D�����ƫ����C
LONG);
        set("exits", ([ /* sizeof() == 3 */
    ]));
        set("item_desc", ([
  "�j��" : "�o�O�j�����j��,�����D�̭��O���O�ٷ|���H,���ϸյۺV�V��(knock)�H\n",

]));
        set("no_fight",1);
        set("no_cast",1);
        set("no_exert", 1);
        set("no_steal", 1);
        set("world", "past");
        set("no_clean_up", 0);
        set("light",1);

        setup();
}

void init()
{
        add_action("do_push","push");
        add_action("do_knock","knock");
}

int do_push(string arg)

{
        object me = this_player();
        string gender;
        gender=me->query("gender");

        if( arg != "�j��" && arg != "door" )
                return 0;
        if ( gender=="�k��" ) gender="�֫L";
        if ( gender=="�k��" ) gender="�L�k";
        if ( me->query("age") > 50 ) gender="�e��";
message("world:world1:vision",
HIY"�j�����ǥX�}�}���H���n....................................................�I�I\n\n"
HIW"�ǻ�����"+gender+"�A����e�ӡA�D���a���ʦ~�L�H�ү�}�Ѫ��u"YEL"�j������"HIW"�v�I�I\n"
NOR+CYN"���{ ��ť�D���ƫ�A�K��ӿ��ĤF�_�ӻ��D�G"HIC"�i�̡i"HIW+me->query("name")+HIC"�j�A���ѧA���x�ѡA�񰨹L�ӧa�I�I\n\n"
HIG"\t\t���ɥj���W�U�A�����F�@�}�}���檺����A
"NOR+GRN"\t\t�Ӫﱵ�ǻ����i�̡y"HIW+me->query("name")+NOR+GRN"�z���D�ԡI�I\n\n"NOR,users());
        me->move(__DIR__"castle1");
        tell_room(environment(me), HIW"�u��"+me->name()+"�ϫl�����}�F�����A���F�i�h�I\n"NOR, ({ me }));
        me->start_busy(1);
        
        return 1;
}
int do_knock(string arg)

{
        object me = this_player();

        if( arg != "�j��" && arg != "door" )
                return 0;
        message_vision(HIY"$N�V�F�V����,���O�L�F�\\�[�٬O�L�H�^��,�uť���̭���ӱx�xĬĬ���n���H�o�ɧA�߷Q,�������}(push)�j�����i�h�n�F�I\n"NOR,me);
        tell_room(environment(me), HIW"�u��"+me->name()+"�ΤO���V���۫����A���L�H�^���I\n"NOR, ({ me }));
        me->start_busy(1);
        me->set_temp("knock_door",1);
        return 1;
}


