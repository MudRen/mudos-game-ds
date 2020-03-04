// Room: /open/world1/acme/bonze/b19.c
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "ű�C��");
        set("long", @LONG
�s���k���A�̤s�سy�@�ɭT�ΡA�I��s�y�A���ۼƳB�r���A�ǽm
�]���a�A�����@�B����m�A��o�q�R���U�C���Ť��R�U�ӼƹD���y
�A�צp�@���A����V�b�šA�O�H�߾K�A�ɺ��U�{�C
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"b18",
]));
set("objects",([
    __DIR__"npc/hua" : 1,
]) );
        set("outdoors","land");
set("item_desc",([
        "�r��":"�J�Ӥ@�ݡA�r���᭱���G���Ӥs�ޡA�i�H�i�h(enter)�ݤ@�ݡC\n",
        "�T��":"�@���ᬰ�}�ꪺ�T�ΡA���ɦ��ƹD���w�q�W�γ��C\n",
]) );

        setup();
}

void init()
{
/// close by tmr 
// ���alestat ���@�N�A���� �a�����ϰ�
//        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        int invis;
        object me;
        me=this_player();
        if(me->is_busy()) return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
        if(arg != "�r��" && arg != "waterfall") return notify_fail("�A�n�i�J����?\n");
        invis=me->query_temp("invis")+me->query_temp("hide");
        if(!invis) message_vision("$N�i�J�F�r���C\n",me);
        me->move(GROUND_TEMPLE"room-47.c");
        if(!invis) tell_room(environment(me),me->name()+"�q�r���~���F�i�ӡA��������z�F�Q���T�V�C\n",({me}));
        me->water_effect(); //�w�q�bchar.c
        return 1;
}

