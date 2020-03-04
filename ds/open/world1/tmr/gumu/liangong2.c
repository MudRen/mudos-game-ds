// Room: /d/gumu/liangong2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
      set("short", HIR"�m�\\��"NOR);
        set("long", @LONG
�@���۫ǡA�Ϊ��ƬO�_�S�A�n(southwall)���_(northwall)�e�A��
����ΡA�F(eastwall)��b��A��(westwall)��o�@�T�����C�ǳ��۪O
�W(top) �躡�ѯ�᯾�Ÿ��A���O�H�Q���覨�A�β`�βL�A��L�W�h�C
���B�ѥj�ӧ̤l�׷ҤJ���~�\�C
LONG    );
        set("exits", ([
                "south" : __DIR__"mudao17",             
        ]));
        set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/stake" : 2, // ���H
        ]));
        setup();
}

void init()
{
        add_action("do_xiulian", "xiulian");
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
}

int do_xiulian(string arg)
{
         mapping fam;
        object me = this_player();
        int c_exp, c_skill;

        if ( !arg ) 
                return notify_fail("�A�n�ѷӭ����ӭ׷ҡH\n");

        // add by tmr 2006/10/23        
          return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
        
        c_exp=me->query("combat_exp");
        if (!(fam = me->query("family")) || fam["family_name"] != "�j�Ӭ�")
          return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if (me->query("jing") < 20)
                return notify_fail("�A��O���ධ���A�h�y�@�����a�C\n");
        if ((int)me->query_skill("literate", 1) < 30)
                return notify_fail("�A�X��r���Ѥ@�Y���A�⮩��ԣ�H\n");
        if (arg == "top")
        {
                if ((int)me->query_skill("sword", 1) < 20)
                        return notify_fail("�A�򥻼C�k�Ӯt�A�L�k��ߥ��u�C�k�C\n"); 
                if (me->query_skill("quanzhen-jian", 1) >= 1)
                        return notify_fail("�A�w�g�Ƿ|���u�C�k�A�ۤv�n�n�m�a�C\n");      
                write("�A�����ǳ����ϯ��A�ߤ��������u�C�k���맮���B�C\n");
                me->receive_damage("jing", 5);
                me->improve_skill("quanzhen-jian", 2);
                return 1;
        }
        if (arg == "southwall")
        {
                write("�A���x�A�V�n���۾��A���@�n�Q�_�h�ƨB�A���u�@�}�ĳ¡C\n");
                c_skill=(int)me->query_skill("strike", 1);
                if (c_skill > 50)
                        return notify_fail("�A�x�O�����A���ӦA���m�Z�O�F�C\n");
                me->receive_damage("jing", 5 + random(15));
                if (c_skill*c_skill*c_skill/10<c_exp)
                        me->improve_skill("strike", random(me->query("int")));
                return 1;
        }
        if (arg == "northwall")
        {
                write("�A���������_���A�ۯ��|�q�A�A�]�Q�ۤv���r�l�_�h�ƨB�C\n");
                c_skill=(int)me->query_skill("unarmed", 1);
                if (c_skill > 50)
                        return notify_fail("�A���O�w��r�L��A�o�L�ƩۼơC\n");
                me->receive_damage("jing",5 + random(15));
                if (c_skill*c_skill*c_skill/10<c_exp)
                        me->improve_skill("unarmed", random(me->query("int")));
                return 1;
        }
        if (arg == "eastwall")
        {
                write("�A¶�F���۾���ۼC�B�A�Τߴ������W�C�k����C\n");
                c_skill=(int)me->query_skill("sword", 1);
                if (c_skill > 50)
                        return notify_fail("�A��۾��W�ҭz�C�k�w���M�x���A�L���A�O�O�F�C\n");
                me->receive_damage("jing", 5 + random(15));
                if (c_skill*c_skill*c_skill/10<c_exp)
                        me->improve_skill("sword", random(me->query("int")));
                return 1;
        }
        if (arg == "westwall")
        {
                write("�A������A����譱�۾��A�Ӥ߾޽m�t�������o��աC\n");
                c_skill=(int)me->query_skill("throwing", 1);
                if (c_skill > 50)
                        return notify_fail("�A�t�����o�H�ߡA�A���ണ���_���C\n");
                me->receive_damage("jing", 5 + random(15));
                if (c_skill*c_skill*c_skill/10<c_exp)
                        me->improve_skill("throwing", random(me->query("int")));
                return 1;
        }
        return notify_fail("�A�L�k�ѷӨ����ӭ׷ҡC\n");
}

int do_tui(string arg)
{
        object me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if ( arg == "eastwall")
        {
//                if(!(fam=me->query("family")) || fam["family_name"] != "�j�Ӭ�")
//                        return notify_fail("�A���O�j�ӶǤH�A����i�J�j�ӱK�ǡI\n");

                message_vision(YEL "$N�����b�ꪺ�������F�X�U�A�@���j�۽w�w���}�A�{�X�@���}���C\n"NOR, me);
                set("exits/enter", __DIR__"liangong3");
                me->receive_damage("ap", 30);
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
        }
      return notify_fail("�A�n������H\n");
}

void close(object room)
{
        message("vision", HIY"�j�ۺC�C�h�^�F���A�S�צ�F�J�f�C\n"NOR, room);
        room->delete("exits/enter");
}

