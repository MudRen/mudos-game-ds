// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object ob;
	int i,check;
	string type,msg,*parts;
	mapping apply;
	if( !this_object() ) return 0;
	if(!arg)
	{
		notify_fail("�A�Q�Y����??\n");
		return 0;
	}
	if( !this_object()->id(arg) ) return 0;
	if(!this_object()->query("no_get")) //���O��b�a�W��
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	check=0;
	if(mapp(apply=this_object()->query("heal"))) {
		parts=keys(apply);
		for(i=0;i<sizeof(parts);i++) {
			if(this_player()->query("max_"+parts[i])>this_player()->query(parts[i])) {
				this_player()->receive_heal(parts[i],apply[parts[i]]);
				check++;
			}
		}
	} 
	if(mapp(apply=this_object()->query("cure"))) {
		parts=keys(apply);
		for(i=0;i<sizeof(parts);i++) {
			if(this_player()->query("wound/"+parts[i])>0) {
				this_player()->receive_curing(parts[i],apply[parts[i]]);
				check++;
			}
		}
	}

	if(this_object()->eat_effect(this_player())) check++;
	if(!this_object()) return 1;
	if(!check) return notify_fail("�A�ثe�èS�����n�A��"+this_object()->name()+"�C\n");
	else if( this_player()->is_fighting() ) this_player()->add_block(1);

	this_object()->set("value", 0);
	if(stringp(msg=query("eat_msg")))
		message_vision(msg+"\n", this_player(),this_object());
	else message_vision("$N���_$n, �@�f��]�F�U�h�C\n", this_player(),this_object());
	// This allows customization of eating effect.
	query("pill/function");
	if(stringp(msg=query("eff_msg"))) tell_object(this_player(),msg+"\n");
	this_object()->finish_eat();
	
	if(this_object()) destruct(this_object());

	return 1;
}

int is_pill() { return 1; }
