inherit NPC;

void create()
{
set_name("�ѹ�",({"mouse"}));
        set("race", "���~");
set("level",3);
set("age",5);
set("long","�A�ݹL�@���Ǧ⪺�p�ѹ��Q���i�R�C\n");
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"}));
 set("verbs", ({ "bite"}));
set("chat_chance",30);
set("chat_msg",({
(:command("east"):),
(:command("west"):),
(:command("north"):),
(:command("south"):),
}));
        setup();
}
init() 
{
if (this_player()->query_temp("kill_king")==1)
{
write("[1;36m�ѹ��𼫪���:�ڭn���ڰ��j�����������C[m\n");
kill_ob(this_player());
}
}
