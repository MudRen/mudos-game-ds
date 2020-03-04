#include <ansi.h>
#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short",HIC"���Ѿ�"NOR);
 set("long",@LONG
�A�{�b�ש󯸦b�o�y���x���W�A���x���a�O�O�ѫC�۩�
�Q�����A�ݰ_�Ӧ��G�O�@�y���q�����Ѿ¡A�ߤ@�������P��
�a��O�A���Ѿª��|�P���|�y���P�C�⪺�J���A���O���C�A
���A�աA�ǡA�Ӥ������@�Ӫ��⪺���x�A�j����A���y�ڡA
�W�����@�ӥW���A�̭����G�i�H��i����F��....
LONG
    );
 set("exits",([   "west":__DIR__"ten8",
               "east":__DIR__"ten7",
    ]));
set("item_desc",([
        "�W��" : CYN"�J�Ӥ@�ݡA���x�W���T�ӥW���A���O�O�y���W���A�����W���A�Τ⫬�W��....\n"NOR,
       "�⫬�W��" : CYN"�N�O�⫬���W����! �ݨӥi�H��i����F��..(putin)\n"NOR,
       "�����W��" : CYN"�N�O�������W����! �ݨӥi�H��i����F��..(putin)\n"NOR,
        "�y���W��" : CYN"�N�O�y�����W����! �ݨӥi�H��i����F��..(putin)\n"NOR,
]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_putin","putin");
}
int do_putin(string arg)
{
       object me,ob,ghost,mask;
        me=this_player();
        ob=this_object();
      if ( arg == "mask")
      {
        if(!objectp(mask=present("faceoff mask",me) ) )
                return notify_fail("�A���W�S�����㤧�����F��C\n");
        destruct(mask);
        message_vision("$N�N�@�ӭ����i�y���W���C\n",me);
        message_vision(CYN"\n�@�Ѹ{�䤧��q���Ѿª��ʤf���_�X!\n"NOR,me);
      ob->set("mask",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }
    if ( arg == "leggings")
      {
        if(!objectp(mask=present("baal leggings",me) ) )
                return notify_fail("�A���W�S���@�L�������F��C\n");
        destruct(mask);
        message_vision("$N�N�@���@�L��i�����W���C\n",me);
        message_vision(CYN"\n�@�Ѧ�{����q���Ѿª��ʤf���_�X!\n"NOR,me);
      ob->set("leg",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }
     if ( arg == "gloves")
      {
        if(!objectp(mask=present("uchimaha gloves",me) ) )
                return notify_fail("�A���W�S����M�������F��C\n");
        destruct(mask);
        message_vision("$N�N�@����M��i�y���W���C\n",me);
        message_vision(CYN"\n�@�ѵ±�����q���Ѿª��ʤf���_�X!\n"NOR,me);
      ob->set("glove",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }

}

void open_war1(object me,object ob)
{
        int i;
       message("world:world1:vision",
           MAG"\n�i�Q�U�j�s�j"+HIR"���Ѿ©��MŢ�n�b�@����{�����A�T�D�ʦL�ħĥi�M�I�I\n\n"+NOR,users());
        call_out("open_war2",3);
        return;
}
void open_war2(object me,object ob)
{
        int i;
        object g;
       message("world:world1:vision",
           MAG"\n�i�Q�U�j�s�j"+HIR"�Q�U�ͦ��L�ש�Q�Ѷ}�A�_���~���L���s�^��_�ٮp�I�I\n\n"+NOR,users());
        g=new(__DIR__"npc/eq/white_wrists");
        g->move("/u/f/faceoff/area/sky/ten9.c");
        return;
}

