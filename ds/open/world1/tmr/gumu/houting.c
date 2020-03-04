// Room: /d/gumu/houting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���U");
        set("long", @LONG
�U�W�]�O�ſ������S���\�\�]�A���e��g�ۤ@��j�r�A�F����
�����ۤ@�T�e�C�譺 (westpic)���e���O��Ӥk���A���O�j�Ӭ����v
�L�L�­^�M�v���C�C���v���A�F�� (eastpic)�e�����o�O�@�ӹD�h�C
�譱�i�H�ݨ즳�@���t��(door)�C
LONG
);
        set("exits", ([
                "east"  : __DIR__"mudao18",
                "north" : __DIR__"mudao07",
                "south" : __DIR__"mudao19",
        ]));
        set("count", 1);
        set("item_desc", ([
        "door" : "�@���p�����۪��A���ȷȪ����S�����C�A�{�u�ݤF�ݡA�o�{���䪺�۾��W���G�����s(press button)�i�H�}���C\n",
        "westpic" : HIM"�e����өh�Q�A�@�ӤG�Q�������A���b����ާ��A�e���訽�M�X�k���e�������A�q�ܤJ�K�A\n
                        �����o�����a�ۤ@�h����A���O�j�Ӭ��v�L�L�­^�C�t�@�ӬO�Q���������X�U�A������֡A\n
                        �b�Ǧ��ԡA�w�A�i�šA���y�X��A�Z�ӫK���F�p�s�k���v�šC\n"NOR,
         "eastpic" : HIC"�����D�H�����ư��A�y�a���C�A�k�⭹�����۪F�_���A�u�O�I��V�~�A�����o�ݤ����C\n"NOR,
        "�r" : HIR"\t�J�ڥj�ӡA����(tuo)�����A�������\\�A���گ��v�C\n"NOR,
        ]));
        setup();
}

void init()
{ 
        add_action("do_ketou", "kneel"); 
        add_action("do_tuo", "tuo");
        add_action("do_an", "press");
}
 
int do_ketou(string arg)
{
        mapping fam;
        object me = this_player();

        if ((!arg) || (arg != "westpic")) return 0;
        message_vision("$N�V����ˡA�����Φa�A�����q�q�V���v�C�C���e���W�F�@���T�Y�C\n", me);


        me->add_temp("marks/ketou", 1);
          me->receive_damage("hp", 5);
/*
     if(me->query_temp("marks/tuo") == 2 &&
                me->query_temp("marks/ketou") == 4 &&
                (!(fam = me->query("family")) ||
                fam["family_name"] != "�j�Ӭ�") &&
                me->query("combat_exp") < 10000)
        {
                me->set("family_name", "�j�Ӭ�");
                me->set("title", HIW"�j�ӶǤH"NOR);
                me->create_family("�j�Ӭ�", 5, "�ǤH");
                me->set("class","swordsman");
                write(HIR"���ߧA�ۺ@�����@�W�j�ӧ̤l�C\n"NOR);
                me->delete_temp("marks/tuo");
                me->delete_temp("marks/ketou");
                return 1;
        }
*/
/*
        if (me->query_temp("marks/ketou") == 15 )
        {
                me->delete_temp("marks/ketou");
                if (query("count") == 0)
                        return notify_fail("�a�W�S�X�@��p�աA�������ŪŦp�]�A�Q�����H���A�U��F�C \n");
                message_vision(HIY "$N���e���ۦa��M�U�I�A�S�X�@����_�͡A$N�⥦�ߤF�_�ӡC\n"NOR, me);
                set("count", 0);
                new(__DIR__"obj/goldkey")->move(me);
        }
*/
        return 1;
}

int do_tuo(string arg)
{
        object me = this_player();

        me->receive_damage("ap", 5);
//        if (me->query_temp("marks/tuo") == 2)
//                return notify_fail("�A����F�S���H\n");
        if ( arg=="eastpic")
        {
                message_vision("$N�¤��������e��������F�@�f�C\n", me);
  //              me->add_temp("marks/tuo", 1);
                return 1;
        }
        return notify_fail("�A���n�H�K�ó�f���ڡI\n");
}

int do_an(string arg)
{
        object room, me = this_player();

        if( !arg || arg != "button" )
        {
                message_vision("�A�b�۾��W�ë��@��A���F�@��ǡAԣ�]�S�N�ۡC\n", me);
                return 1;
        }
        if( query("exits/west"))
        {
                return notify_fail("�۪��w�g�O�}�ۤF�C\n");
        }
        if( me->query_skill("unarmed", 1) > 10)
        {
                message_vision("$N���b�۪��e�A�]�����b�������F�@�U�A�۪��s�s�T�ۡA�w�w���}�F�C\n", me);
                if( !(room = find_object(__DIR__"mudao06")) )
                        room = load_object(__DIR__"mudao06");
                set("exits/west", __DIR__"mudao06");
                room->set("exits/east", __DIR__"houting");
                tell_room(room,"�uť�o�۪��b�s�s�n���Q�w�w���}�C\n");
                remove_call_out("close");
                call_out("close", 5, me);
        }
        else
                message_vision("$N�յۦb�۾��W���ӫ��h�A�i�O�۪��������ʡA�u�o�}�F�C\n", me);
        return 1;
}

void close(object me)
{
        object room;

        tell_room(this_object(), "�۪��w�w�a���W�A��_�F�쪬�C\n");
        delete("exits/west");
        if( !(room = find_object(__DIR__"mudao06")) )
                room = load_object(__DIR__"mudao06");
        room->delete("exits/east");
        tell_room(room,"�F�𪺷t���w�w�a���W�F�C\n");
}

