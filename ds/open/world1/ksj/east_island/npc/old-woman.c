#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "�ѱC�C", ({ "old woman","woman"}));
        set("long", "�@��Mħ�i�˪��ѱC�C�A�g��۶��{�p�u�l�A�o�������{�i�O�ܦn�Y����C\n\n");
        set("level",10);
        set("title","�Mħ�i��");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 60);
        set("evil",-70);           
        set("no_fight",1);
        set("attitude", "peaceful");  
        set("talk_reply","�ȤH�O�~�a�Ӫ��a�A�R�Ƕ��{���W�i�H�Y�C");
        set("sell_list",([   
           __DIR__"eq/yaki-onigiri"  : 5, 
        ]));
        set("chat_chance", 10);  
        set("chat_msg", ({     
            "�ѱC�C�۹D�G�ӳ��n�Y�����{���\n",
            "�ѱC�C����洤���F�X���A�@�U�l���X�@�Ӻ}�G�����{�C\n",
            "�ѱC�C���_��y���F���y�W�����C\n",
            "�ѱC�C�§A�o��L�L�@���C\n",
           (:command("smile"):),
         }));
         setup();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
