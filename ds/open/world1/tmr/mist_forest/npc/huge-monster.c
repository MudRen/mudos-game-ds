#include <npc.h>

void create()
{
        set_name("���]�~", ({ "huge monster","monster" }) );
        set("long",@long
    �o�O�@�����o�D�`���j���]�ԡA�A�i�H�M���@���e������������
�u��A�Ӫ��p�h���Ӵ��o�����������������ۧA�A�e�Ⱖ���u���i�ν��A
�����ۤ��j�ڦp�¦��K����y�U�����ҡA���G�H�ɳ��i�H��A������b�C
�A���ۨe���e�A�j���٤��Ψe���y���C
long
);
        set("title","�g���˪L");
        set_race("human");
        set("age", 200);
        set_skill("twohanded axe",80);
        set_skill("parry",100);
        set_skill("dodge",100);
        // �����]�~�A��o�� 20�I�n��
        set("bounty",([
                  "reputation": 10,  
        ]) );
        set("attitude", "aggressive");
        setup();
        set_level(30);
        carry_money("gold", 1);
        /* �򥻸˳� */
        carry_object(__DIR__"obj/evilmonster-armor")->wear();
        carry_object(__DIR__"obj/python-belt")->wear();
        carry_object(__DIR__"obj/evil-axe")->wield("twohanded axe");
}
void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}

int intercept(string arg)
{
        
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�@������A�פF�U�ӡC\n");
    return 1;
}

int intercept2()
{
        
    if( !this_player()->visible(this_object()) ) return 0;
    write( name() + "�@������A�פF�U�ӡC\n");
    return 1;
}

        
