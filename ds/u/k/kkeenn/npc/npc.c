#include <ansi.h>;

inherit NPC;

void create()
{
            set_name(HIM"������"NOR,({"efghijk","system"}) );
           set("age",15);
      set("title",HIB"�i"HIC"�s�M�h"HIW"��"RED"��"HIB"�j"NOR);
	set("gender", "�k��");
         set("level",100);
         set("nick",HIC"����"NOR);
	set("long",
"�o�O�C�s�L���P�Ǥ��@, �]���Y�دS���], �ҥH�S�OClone�X��^^ \n"
);
	set("chat_chance",5);
	set("chat_msg",({
                (:command("sing"):),
                HIM"������"NOR"�b"HIC"�C�s�L"NOR"����̨Ӯ̥h..\n",
	}) );
set_skill("unarmed",100);
set_skill("dragonfist",100);
set_skill("sword",100);
set_skill("dragonsteps",100);
set_skill("dragonblade",100);
map_skill("unarmed","dragonfist");
map_skill("dodge","dragonsteps");
map_skill("blade","dragonblade");
set("inquiry",([
  "money" : "��...�{�b�N�n�v??�ںɶq���A�աC\n",
  "kkeenn" : "�L��...�O�ڪ��D�H..ť���O�@�W�s�M�h���C\n",
"�s�M�h": "��...�n���O�ǻ�����¾�~��..�S�x�O�M�ۤ@���s^^",
"�s" : "��...�o�A�ݧڴN��F^^�s�N�b�a�U�s�찱�۳�",
]) );

	setup();
}

void init()
{
add_action("hest","hest");
}
int hest(string str)
{ 
object me,ccc;
me=this_player();
if(!objectp(ccc=present("item",me) ) )
return notify_fail(HIR"ĵ�i.�L���������̤��o����C\n"NOR);
command(str);
  return 1; 
}

