// damen.c �j��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int valid_leave();
string look_gate();
int do_knock(string arg);

void create()
{
        set("short", "���u�Фj��");
        set("long", @LONG
�A�w����F�׫n�s�b�s�y�A�e���N�O���u�Ъ��`�������c�F�C��
�t�̤s�ӿv�A���C�������P�C�P��j��˴ˡA�A�˦��L�A����M�աC
���e�����ѥˡA����¼���A�����@�D�G�V�Ӽe�A�T�V�Ӱ���������
��]�ɤj��(gate)�A��դ��Z�C���W���ۤ@����(bian)�A���e���۬W
�W���ۤ@�ƹ��p(duilian)�C
LONG
        );
        set("exits", ([
                "westdown" : __DIR__"jiaobei",
        ]));
        set("outdoors", "chongyang");
        set("item_desc", ([
            "gate":
"�@�D�T�V�Ӱ���"HIR"��������"HIY"�]��"NOR"�j���C\n",
            "bian": HIG"
��������������������������
�����@�@�@�@�@�@�@�@�@����
�����@���@�u�@�j�@��  ����
�����@�@�@�@�@�@�@�@�@����
��������������������������
\n"NOR,
            "duilian": BLINK+HIW"
�@�ͤG�G�ͤT�T�͸U��\n
�a�k�ѤѪk�D�D�k�۵M
\n"NOR
        ]) );
        set("objects",([
                CLASS_D("quanzhen")+"/zhike" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
}

void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "��a�@�n�A�̭����H��j�����W�F�C\n",
            this_object());
        room->delete("exits/south");
        if (objectp(present("qingguan", room)))
            message("vision", "���ȹD���W�e��j�����F�_�ӡC\n", room);
        else
            message("vision", "�D���W�e��j�����F�_�ӡC\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("�j���w�g�O�}�ۤF�C\n");

    if (!arg || (arg != "gate" && arg != "east"))
        return notify_fail("�A�n�V����H\n");

    if(!( room = find_object(__DIR__"datang1")) )
        room = load_object(__DIR__"datang1");
    if(objectp(room))
    {
        set("exits/east", __DIR__"datang1");
        message_vision("$N�����a�V�F�V���A�uť�s�a�@�n�A"
            "�@��D�����n���}�j���A\n"
            "�L��ĵ�����إ��W�W�U�U���q��$N�C\n",
            this_player());
        room->set("exits/west", __FILE__);
        message("vision", "�~���ǨӤ@�}�V���n�A�D�����n�W�e��j���}�C\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if ( dir != "east" )
    {
        return ::valid_leave(me, dir);
    }
    if (!query("exits/east"))
        return 0;

    if (!::valid_leave(me, dir))
        return 0;

    if ( (me->query("family/family_name") == "���u��"))
    {
        if (me->query("class") != "quanzhen")
        {
            return notify_fail("�D�����D�G�藍�_�A�U�a�̤l���o�J�c�צ�C\n");
        }
        write("�D���������}�A���D�G�v�S���W�F�A�жi�C\n");
        return 1;
    }
    else if( present("chongyang ling", me) )
    {
        write("�D�����ӽ]���A�������}�A���D�G��ӬO�Q�Ⱦr��A�жi�жi�I\n");
        return 1;
    }
    if (me->query("shen") >= 0)
         return notify_fail("�D�����D�G�o��I�D�Ц^�}�A�����c�����ݫU�H�C\n");
    return notify_fail("�D�����D�G�A�����]�~�D�A�����c�V�����ǡA�ФF�I\n");

}