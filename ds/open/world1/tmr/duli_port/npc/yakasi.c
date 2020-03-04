// smith.c

#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("�ȥd�q", ({ "yakasi smith","smith" }) );
        set_race("human");
        set_attr("str", 20);
        set_attr("cor", 20);
        set_attr("cps", 15);
        set_attr("dex", 18);
        set("age",35);
        set("title","�Z����");
        set("long",@long
�ȥd�q�O�@�Ө��j�鰷�����~���K�K�A�L�ҳc�檺�Z���~��A�b�o��
��i�O�D�`���W�n���C�p�A���N�V�L�ʶR�Z���A�i�H�Q��list���O�d
�ߥi�ʶR�������C
long
);

        set("merchandise", ([
                __DIR__"obj/longsword": 5,
                    "/d/obj/axe": 5,
                 __DIR__"obj/bigblade": 5,
                    "/d/obj/longpike": 5,
                    __DIR__"obj/electric-stick": 2,
                      __DIR__"obj/wood-axe": 5,
                      __DIR__"obj/wood-blade": 5,
                
        ]));

        set("chat_chance", 5);
        set("chat_msg", ({
                "�ȥd��ΤO���F���i�y�A���D�G�u�C�ѳ��o�򦣡A�u�O���a�F�C�v�C\n",
                "�ȥd���I�_�F�@�ڭ��ϡA�ΤO�`�`�a�l�F�@�f�C\n",
        }));
        setup();
	advance_stat("gin",200);
	advance_stat("hp",200);
     set_level(10);
	 do_heal();
     carry_object(__DIR__"obj/flysky-dagger")->wield();
}

int accept_fight()
{
        do_chat("�ȥd��λ�l��F�@�n�A�z�]���z�A...\n");
        return 0;
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

