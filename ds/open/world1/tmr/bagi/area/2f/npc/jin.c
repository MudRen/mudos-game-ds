#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�ۦʤ�", ({ "shi bai-jin","shi","jin"}) );
        set("level",40);
        set("long",@long
    �ۦʤ�O�G�Q�~�e�������W���j�N�x�A�����O�x�B�ժZ���O�A��{��
�ժ����A�b�Գ��W��O�ªZ�L�ġA�i�߾ԥ\�A�S�X�ӤW��u���~�N�x�v
�W���A���ȩx���o�N�ɡA�����M�q����W�������L�v�L�ܡA��������|�X
�{�b�b�o�̡C
long
           );
        set_skill("dodge",75);
        set_skill("parry",75);
        set_skill("sword",80);
        set("age",54);
        set("title","���~�N�x"NOR);
        set("chat_chance", 8);
        set("chat_msg", ({
                (:command("sigh"):),
                "�ۦʤ�ĹD�G���Ƿ�~�]�g��¬�A���o�Q�x�b���G�Q�~...\n",
        }) );
        setup();
        carry_object(__DIR__"wp/sword")->wield();
        carry_object(__DIR__"eq/armor")->wear();
        carry_object(__DIR__"eq/shield")->wear();
        carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"obj/key");
}

