// Room: /d/gumu/woshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"�׫�"NOR);
        set("long", @LONG
�o���O�p�s�k�~���׫ǡA�Ф��ŪŬ}�}�C�k���O�@�������C�ۧ@
�� (bed)�A�ɤW�Q�F�i��u�A�@�T�ե���@���Q�A���~���F�@�ڤH����
÷����L�Ǥ��A�ǥ��ߵۤ@�Ӳ��W���o(cabinet)�C
LONG    );
        set("item_desc", ([
                "bed" : "�@�i�Ѵ��q�C�۾Q�����ɡA�ɨ����B�A���@����_���۪O(stone)�A���i���(twist)�C\n", 
                "cabinet" : "�@�y���q�������o�l�A�����D�O�_�i�H���}(open)�C\n", 
        ]));
        set("exits", ([
                "east" : __DIR__"mudao15",
        ]));
        set("chu", 1);
        setup();
}

void init()
{
        add_action("do_tang", "lie");
        add_action("do_ban", "twist");
        add_action("do_open","open");
        add_action("do_xian","lift");
}

int do_tang(string arg)
{
        object me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۡC\n");

        if ( arg == "bed")
        {
                message_vision(CYN "$N���������b�C�ۨ���ۧɤW���C\n"NOR,me);
                me->set_temp("marks/��", 1);
                return 1;
        }
        return notify_fail("�A�n���b�a�W�A�p�ߵ۲D�@�I\n");
}  

int do_ban(string arg)
{  
        object me=this_player();

        if (!me->query_temp("marks/��")) {
                write("�A�S��(lie)�ɤW�A���ȥΤ��W�O�a�I\n");
                return 1;
        }

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����۩O�I\n");

        if ( arg == "stone")
        {
                if (me->query("ap") < 200)
                        return notify_fail("�A�ϥX�Y�����l�O�A���۪O�o�������ʡC\n");

                message_vision(HIY "$N�ΤO��ʬ�_���۪O�A�uť�o���X�T�A�ۧɤw���J�U�h�۫ǡC\n"NOR,me);
                me->add("ap",-100);
                me->delete_temp("marks/��");
                me->move(__DIR__"shishi0");
                write(HIY"�ǳ��۾��S�C�C�ۦ���W�F�C\n"NOR);
                return 1;
        }
    return notify_fail("�A�n�椰��H\n");
}

int do_open(string arg)
{
        object ob, me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if ( arg=="cabinet")
        {
                if ( query("chu") == 1 )
                {
                           if(!objectp(present("gold key", me)))  {
                                write("�A�S���_�͡A�L�k�}�C\n");
                                return 1;
                        }
                        message_vision("$N�C�C�Ϊ��_�ͥ��}�F�o���C\n",me);
                        ob=new(__DIR__"obj/box");
                        ob->move(environment(me));
                        write("�A�o�{�o����ۭӪ���Ϊ��K���l�A�����D�O�_�i�H�ȶ}(lift)�C\n");
                    destruct(present("gold key", me));
                        return 1;
                }
                else
                {
                        write("�A�ӱߤF�A�o���{�b�}�۩O�C\n");
                        return 1;
                }
        }
        write("�A�n�}����H\n");
    return 1;
}

int do_xian(string arg)
{
        object suo, me=this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("�A�����ۭ��I\n");
        if ( arg =="box")
        {
                 if(!(present("iron box", environment(me)))) 
                           return notify_fail("�o���S�������K���C\n");
                if(!objectp( present("silver key", me)))        
                            return notify_fail("�A�S���_�͡A�L�k�}�ҪF��C\n");
                me->delete_temp("marks/�K��");
                message_vision("$N�λ��_�Ͷ}�F��A�����ȶ}�F�K���C\n",me);
                  suo=new(__DIR__"npc/obj/yinsuo2");
                if(!clonep(suo))
                        return notify_fail("�A�ӱߤF�A���l�����ŵL�@���C\n");
                write("�ȶ}�K���A�A�o�{������ۤ@�ΦB�`�몺���ơC\n");
                suo->move(me);          
                 destruct(present("iron box", environment(me)));
                  destruct(present("silver key", me));
                return 1;
        }
    return notify_fail("�A�n�ȶ}����H\n");
}


