inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "�K�K", ({ "smith" }) );
        set("gender", "�k��" );
	set("level",1);
        set("age", 22);
        set("long",
                "�@�Ө����ʧ����K�K�M�����L�a�u�@�ۡC\n"
                "�p�G�A�Q�R�@���K���M�i�H�� list �ݦ����ǪF��M�� buy �V�K�K�ʶR�C\n"
	);
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "�K�K�N�@���N�����K���u��v�a�@�n���J�@�Ǫ����c���C\n",
                "�K�K�Τ⤤���K��b�K�z�W�ΤO�V���C\n",
                "�K�K���D�R���}�I�M�p�ߧO�S�ۤF�C\n",
                "�K�K���D�R�� ... �u��ڵ����a�F�C\n",
        }));
	set("sell_list",([	
                 __DIR__"wp/sword"        : 20, 
                 __DIR__"wp/shortsword"   : 23, 
                 __DIR__"wp/shortaxe"     : 20, 
                 __DIR__"wp/dagger"       : 15, 	
                   __DIR__"wp/fist"       : 20,     
                     __DIR__"wp/fork"       : 20,     

        ]) );
            setup();
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}


