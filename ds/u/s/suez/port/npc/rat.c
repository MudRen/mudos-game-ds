inherit NPC;
void create()
{
	set_name("�ѹ�", ({"rat"}) );
	set("long", "�|�s�s�s���ѹ��A�|�|�B�]���ѹ��A�c�����t���ѹ��C\n");
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "����", "�}"})); //���𳡦�
	set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("level",random(5));
	set("int",1);
	set("dex",10);
        set("chat_chance", 3);
        set("chat_msg", ({
             (: random_move :),
              }));
	set("env/wimpy", 50);
	setup();
}
void die()
{
        object ob,obj;
	int temp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
	temp = ob->query_temp("police");
        if( !ob ) 
        {
                ::die();
                return;
        }
	if( ob->query_temp("police_area")!=1) return; 
	temp++;
	ob->set_temp("police",temp);
        ::die();
        return;
}