#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "�Ю{", ({ "giautoo"}));
        set("long", "�L�O�@��b�o������ޯ઺�F�۱бЮ{�C\n");
           set("level",3);
        set("title","�F�۱�");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
 set("evil",-20);                //���c�� 20 (�������c, �t���})
        set_skill("blade",40);          // �ޯ�(�۩w)
        set_skill("parry",20);          //
        set_skill("dodge",30);          //
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("chat_chance",20);
        set("chat_msg",({
                  "�Ю{�V�O���m�ߵۡA�����ٵo�X�ݮ��n�C\n" ,
                  (:command("addoil"):),
         }) );
        setup();
          add_money("coin", 200);           //�a����
}


