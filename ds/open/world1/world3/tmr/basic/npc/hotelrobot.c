#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
          set_name("�s�]����H",({"hotel robot","robot"}));
          set("long","�s�]���D�H�ۤv�b�h�~�e�s�y������H�A�ѩ�w�g���¤F�A\n"
                         "�ҥH�{�b�u�వ�@��²�檺�R��u�@�C\n"
          );
          set("age",50);
          set("level",1);
          set("sell_list",([
                   __DIR__"obj/water_tube"        : 3, 
                   __DIR__"obj/sandwich"        : 3, 
                 __DIR__"obj/iron_shovel"        : 5, 
                   __DIR__"obj/a_lighter"        : 5, 
        ]));
          set("chat_chance",2);
        set("chat_msg", ({
                "����H�N���~�M�����e��ȤH����W�C\n",
                "����H��B�b�M�z��W���U���C\n",
        }));
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
