inherit NPC;
void create()
{
set_name("[1;32m�а�Ԥh[0m",({"church fighter","fighter"}));
set("gender", "�k��");
set("title","[1;31m�ڪB�V���T�̥S[0m");
set("long", "�L�O�ڪB�V���u�q�̤l, �`�E��������ܥL�w�g���F���ֿi�m�C\n");
set("age",36);
set("level",60);
//set_skill("dragon_blade",30);
//map_skill("blade","dragon_blade");
set("combat_exp",26000+random(3000));
set_skill("rapid",100);
set_skill("strike",200);
set_skill("combat",410);
set("evil",-100);
set("coin",random(1900));
set_temp("apply/armor",600+random(200));
set("chat_chance_combat",6);
set("chat_msg_combat",({
(:command,"rapid":),
}));   
setup();
carry_object(__DIR__"eq/greenshield")->wear();
carry_object(__DIR__"wp/stoneaxe")->wield();
}

void die()
{
object ob;
ob=this_player();
tell_room(environment(ob),"\n\n[1;33m�Ԥh���_������ë...[1;32m�D��.. �гj�K�ڪ��F��!![0m\n");
::die();
}