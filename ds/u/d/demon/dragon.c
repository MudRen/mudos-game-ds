#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM "�I�G" NOR,({"dab aqua dragon","dragon"}) );
      set("title",HIM "���s" NOR);
        set("long",@LONG
�u���s  �I�G�v���@�ӥj�ͪ��A�ʳߪ᭻�A�~�󦿡B�򤧤��A�q���G
�Q�|�ءA�����@�H����A�@���ئp���A���������H�H�����W�����C
LONG    
        );
        set("race", "���~");    
        set("unit","��");
        set("age",300);
          set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�s��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",90);
        add("addition_damage",80);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
}

