// maild.c
// �W���ק���: 1999.10.21 0:51
// �W���ק��: Luky
// �ק鷺�e: �ק�mail���T�{
inherit F_DBASE;
void create()
{
  seteuid(ROOT_UID);
  set("name", "�l�t");
  set("id", "maild");
}

varargs void send_mail(string receiver, mapping mail, mixed flag)
{
  object ob,mbx,ppl;

  if(ppl=find_player(receiver))
  {
  		if(!mbx = present("mail_ob",ppl))
  		{
  			mbx = new(MAILBOX_OB);
	       		mbx->set_owner(receiver);
	       		mbx->receive_mail(mail);
	       	} else mbx->receive_mail(mail);
  }
  else
  {	
	  ob = new (LOGIN_OB);
	  ob->set("id", receiver);
	
	  if( !ob->restore() )
	  {
	    write("�S���o�Ӫ��a�C\n");
	    return ;
	  }
	
	  if( !mail || !flag )
	    ob->set("new_mail", 1);
	  else ob->set(mail, flag);
	
	       	mbx = new(MAILBOX_OB);
	       	mbx->set_owner(receiver);
	       	mbx->receive_mail(mail);
	
	  ob->save();
	  //write ("�H�H�X�h�F.\n");
	  destruct(ob);
	  if(mbx)
	  {
	  	if(!environment(mbx)) destruct(mbx);
	  }
  }
}

int check_mail(string id)
{
	 object mbx;
	 if(!mbx = new(MAILBOX_OB)) return 0;
         mbx->set_owner(id);
         return mbx->query_mail_flag();
}

void send_mail_to(string who,mapping mail)
{
	mixed file;
	string dir,ppl,str="";
	int i,j=0;
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("�i��ǰe %s �u�@��..",who));
	if(strlen(who)!=1)
	{
		CHANNEL_D->do_channel( this_object(), "sys", sprintf("�ǰe %s �u�@����..strlen(who)!=1 \n",who));
		return;
	}
	if(!mapp(mail))
	{
		CHANNEL_D->do_channel( this_object(), "sys", sprintf("�ǰe %s �u�@����..!mapp(mail) \n",who));
		return;
	}
	dir="/data/login/"+who+"/";
	file = get_dir(dir, 0);
	if( !sizeof(file) )
	{
		CHANNEL_D->do_channel( this_object(), "sys", sprintf("�ǰe %s �u�@����..!sizeof(file) \n",who));
		return;
	}
//	if( !stringp(file) )
//	{
//		CHANNEL_D->do_channel( this_object(), "sys", sprintf("�ǰe %s �u�@����..!stringp(file) \n",who));
//		return;
//	}
//	i=sizeof(file);
	for(i=0;i<sizeof(file);i++)
	{
		ppl = replace_string( file[i], ".o","");
//		str+=ppl+",";
		j++;
		send_mail(ppl,mail);
	}
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("�ǰe %s �u�@����!!����H��:%d �H ",who,j));
}
//��������ɶ��H���C�t��
void send_mail_to_all(mapping mail)
{
	int delay;
	delay=10;
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("�}�l��%s�ǰe mail ���Ҧ����a!! ",mail["from"]));
		call_out("send_mail_to",5,"a",mail);
		call_out("send_mail_to",delay,"b",mail);
		call_out("send_mail_to",delay*2,"c",mail);
		call_out("send_mail_to",delay*3,"d",mail);
		call_out("send_mail_to",delay*4,"e",mail);
		call_out("send_mail_to",delay*5,"f",mail);
		call_out("send_mail_to",delay*6,"g",mail);
		call_out("send_mail_to",delay*7,"h",mail);
		call_out("send_mail_to",delay*8,"i",mail);
		call_out("send_mail_to",delay*9,"j",mail);
		call_out("send_mail_to",delay*10,"k",mail);
		call_out("send_mail_to",delay*11,"l",mail);
		call_out("send_mail_to",delay*12,"m",mail);
		call_out("send_mail_to",delay*13,"n",mail);
		call_out("send_mail_to",delay*14,"o",mail);
		call_out("send_mail_to",delay*15,"p",mail);
		call_out("send_mail_to",delay*16,"q",mail);
		call_out("send_mail_to",delay*17,"r",mail);
		call_out("send_mail_to",delay*18,"s",mail);
		call_out("send_mail_to",delay*19,"t",mail);
		call_out("send_mail_to",delay*20,"u",mail);
		call_out("send_mail_to",delay*21,"v",mail);
		call_out("send_mail_to",delay*22,"w",mail);
		call_out("send_mail_to",delay*23,"x",mail);
		call_out("send_mail_to",delay*24,"y",mail);
		call_out("send_mail_to",delay*25,"z",mail);
		
}
 