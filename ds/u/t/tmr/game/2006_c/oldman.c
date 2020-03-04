#include <ansi.h>

inherit NPC;

/*

        $NOR$ - ���`�C��        1 ��
        $HIR$ - �G����          2 ��
        $HIG$ - �G���          4 ��
        $HIY$ - ����            8 ��
        $HIB$ - �Ŧ�            16 ��
        $HIM$ - ������          32 ��
        $HIC$ - �ѫC��          64 ��
        $HIW$ - �զ�            128 ��
*/

void initName() {
        int i = random(1000);
        if(i>=990) {
                set_name(HIW "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",128);
                return;
        }
        if(i>=950) {
                set_name(HIC "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",64);
                return;
        }
        if(i>=900) {
                set_name(HIM "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",32);
                return;
        }
        if(i>=850) {
                set_name(HIB "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",16);
                return;
        }
        if(i>=800) {
                set_name(HIY "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",8);
                return;
        }
        if(i>=600) {
                set_name(HIG "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",4);
                return;
        }
        if(i>=400) {
                set_name(HIR "�����W���j���G�ѤH" NOR,({"unknow oldman","oldman","man"}) );
                set("score",2);
                return;
        }
        set_name( "�����W���j���G�ѤH" ,({"unknow oldman","oldman","man"}) );
        set("score",1);
        return;
}

void create()
{
        initName();
        set("long",@LONG
�@�Ӥ�����m�W���ѥ��͡A�ݤ��X�h�j�~���A�d�ۤ@�j����G�l�A��
�y���q�q���ƬO�ũM�A���ۤj���⪺�j��A�˦��_�S�A���O�o�ɥN�����
�A�I�W�t�ۤ@�Ӥj���⪺�U�l�A�ݰ_�ӹ������A�����ˤFԣ���N�C�L�o�{
�A���ݵۥL�A�N��ۧA���������ۡC
LONG
);
        set("age",1200);
        set("level",1);
        set("attitude", "peaceful");
        set("race","�H��");
        set("gender", "�k��" );
        set("chat_chance",60);
        set("chat_msg",({
        (:command("sing �m�m����m�m����a�n�h�T�G���"):),
        "�ѤH���������F�_�ӡA���G�D�`�����C\n",
        "�ѤH���ۻy���D�G�u�@�~���o�U�Ӥ@���A�o����i�ܪ��u�h�ڡC�v\n",
        (:command("say ����ɯɦ�Ҧ��H"):),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        }) );
        setup();
        set("max_hp",1);
        set("hp",1);
        if( random(100) == 1 )
                add_money("gold", 1 + random(10));
        else if( random(100) < 10 )
                add_money("silver", 1 + random(100));
        else
                add_money("coin", 1 + random(1000));

        if(random(10)==1) carry_object(__DIR__"eq/hat")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/cloth")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/gloves")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/boots")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/beard")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/waist")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/pants")->wear();
         if(random(49999)==1) carry_object(__DIR__"eq/ring")->wear();
         if(random(49999)==1) carry_object(__DIR__"eq/ankle")->wear();

               if(random(20)==1) carry_object(__DIR__"eq/box");

        
}



void die()
{
        object ob;
        int sc = query("score");
        if( sc < 1 ) sc = 1;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }

        tell_object(ob,"�A�y���t�ϦѤH��o" + sc  +"�I�n���C\n");
        "/u/t/tmr/game/2006_c/board.c"->addScore(ob, sc);
        ::die();
        return;
}
