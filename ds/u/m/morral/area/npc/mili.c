#include <ansi.h>
    inherit NPC;
object user=this_player();
    void create()
{
set_name(HIG"���F�̲�"NOR,({"elf mili","elf"}) );
set("gender", "�k��");
set("attitude","peaceful");
set("age",5620);
set("long", "�o���ۧA�Q�������@�����F�Ҿ֦����e���w
���v�B�Ѳ��B���աB���a�ۿå����������Y�v�A��M�O�Ӥ޾ɧA���C\n");
set("level",120);
set("evil",-5000);
set_skill("dodge",100);
set_skill("sword",100);
set_skill("parry",100);
set_skill("block",100);
set("chat_chance",50);
set("chat_chance_combat",50);
set("chat_msg_combat",({
(:command,"say �H�H�A�A�O�����L�ڪ����C":),
}));
set("chat_msg",({
(:command,"say �ڬO���Ӫ��޾ɪ̢w�̲���":),
(:command,"say �A�̤@�����nť�ڪ���":),
(:command,"hmm":),
(:command,"say ���ޫ�ˡA�����e���a�A�ݬݦA���C":),
(:command,"smile":),
}) );
  setup();
set("coin",random(5000)); 
}
