inherit NPC;
#include <ansi.h>
inherit SELLMAN;

void create()
{
        set_name(WHT "�Z������H"NOR, ({ "weapon robot","robot" }) );
        set("level",10);
        set("race","����H");	
        set("age", 22);
        set("long",
                "�@�ӥ��b���L�a�u�@�۪�����H�C\n"
                "�p�G�A�Q�R�@�ǪZ���M�i�H�� list �ݦ����ǪF��M�� buy �V����H�ʶR�C\n"
	);
        set("combat_exp", 50);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "����H���b�I��Z���C\n",
                "����H���D: �B�ͦh�R�@�I�A�ڵ��A�@�ӧ馩�C\n",
                "����H�G�s�@�n�R�ѧr�I�I�Ѧ�����h�ȤH�O�H\n",
                "����H�v�v�o�N�a���D�R�ڳo�����O�����̦n���C\n",
        }));
	set("sell_list",([	
                 __DIR__"wp/lasersword"        : 15, 
                 __DIR__"wp/longsword"   : 23, 
                 __DIR__"wp/shortaxe"     : 20, 
                 __DIR__"eq/boots"       : 20,     
                     ]) );
            setup();
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}


