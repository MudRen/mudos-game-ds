// channeld.c
 
#include <ansi2.h>
#include <net/dns.h>
#include <net/emote.h>
#include <mudlib.h>
#define CHANCE 20

string color(string arg, int emote);
string *banned_words = ({
	"�F","fuck","shit","bitch",
});

string *channel_list = ({
    "warn","tw","sys","wiz","gwiz","es","twiz","tchat","chat","ds","rumor","music","sky","dragon","moon","bala","ming"
});

mapping channels = ([
        "warn":  ([      "msg_speak": HBK "�i�`�N�j%s�R%s\n" NOR,
                        "msg_emote": HBK "�i�`�N�j%s" NOR,
                        "wiz_only": 1 ,
                        "cost": 0,
		]),
        "sys":  ([      "msg_speak": HIB "�i�t�Ρj%s�R%s\n" NOR,
                        "msg_emote": HIB "�i�t�Ρj%s" NOR,
                        "wiz_only": 1 ,
                        "cost": 0,
		]),
        "wiz":  ([      "msg_speak": HIY "�i�Ův�j%s�R"HIW"%s\n" NOR,
                        "msg_emote": HIY "�i�Ův�j%s" NOR,
                        "wiz_only": 1 ,
                        "cost": 0,
		]),
        "gwiz": ([      "msg_speak": HBK "�i���ڡj%s�R" NOR "%s\n" NOR,
                        "msg_emote": HBK "�i���ڡj%s" NOR,
                        "wiz_only": 1,
                        "intermud": GWIZ,
                        "channel": "CREATOR",
                        "filter": 1 ,
                        "cost": 0,
		]),
        "es":   ([      "msg_speak": HIR "�i�F��j"NOR"%s�R%s\n" NOR,
			"msg_emote": HIR "�i�F��j"NOR"%s"NOR,
                        "intermud": GCHANNEL,
                        "channel": "es",
                        "filter": (: $1["MUDLIB"]=="Eastern Stories" :),
                        "cost": -2,
                ]),
        "twiz": ([      "msg_speak": HIW "�i�x�W�j%s�R" NOR "%s\n" NOR,
                        "msg_emote": HIW "�i�x�W�j%s" NOR,
                        "intermud": GCHANNEL, 
                        "channel": "twiz",
                        "filter": 
                        (: $1["HOSTADDRESS"][0..2]=="140" ||
                           $1["HOSTADDRESS"][0..2]=="163" ||
                           $1["HOSTADDRESS"][0..2]=="211" ||
                           $1["HOSTADDRESS"][0..2]=="168" ||
                           $1["HOSTADDRESS"][0..2]=="203" ||
                           $1["HOSTADDRESS"][0..2]=="210" ||
                           $1["HOSTADDRESS"][0..2]=="202" ||
                           $1["HOSTADDRESS"][0..2]=="192"
                                :),
                        "wiz_only":1,
                        "cost": 0,
		]),
        "tchat": ([     "msg_speak": HIC"�i����j%s�R"NOR"%s\n" NOR,
                        "msg_emote": HIC"�i�ʧ@�j%s"NOR,
                        "cost": -3,
                ]),
	"chat": ([	"msg_speak": HIG+"�i�ɥN�j%s�R"NOR"%s\n"+NOR,
			"msg_emote": HIG"�i�ɥN�j%s"NOR,
			"world": 1,
			"cost": -2,
                ]),
        "tw": ([        "msg_speak": BBLU+HIW+ " �x�W "+NOR+" %s�R%s\n"+NOR,
                        "msg_emote": BBLU+HIW+ " �x�W "+NOR+" %s"NOR,
                        "intermud": GCHANNEL,
                        "channel": "tw",
                        "filter": (: $1["LOCATION"]=="Taiwan" :),
                        "cost": -2,
                ]),
        "ds": ([        "msg_speak": HBK "�i�ڤۡj%s�R%s\n" NOR,
                        "msg_emote": HBK"�i�ڤۡj%s"NOR,
                        "intermud": GCHANNEL,
                        "channel": "ds",
                        "filter": (: $1["MUDGROUP"]=="�x�W�d���p��" :),
                        "cost": -2,
                ]),
        "rumor":([      "msg_speak": HIM "�i���ǡj%s�R%s\n" NOR,
                        "msg_emote": HIM "�i�y���j%s" NOR,
                        "anonymous": "�Y�H",
                        "cost": -10,
                        "player_listen": 1,
		]),
        "music":([      "msg_speak": CYN "�i���֡j%s: %s\n" NOR,
                        "msg_emote": CYN "�i�۫ߡj%s"NOR,
                        "cost": -1,
		]),
        "game":([      "msg_speak": BGRN+BLK+"�i�C���j"+NOR+" %s: %s\n" NOR,
                        "msg_emote": BGRN+BLK+ "�i�C���j"+NOR+" %s"NOR,
                        "cost": -1,
		]),
        "dragon":([     "msg_speak": GRN "�i�g�s���j%s: %s\n" NOR,
                        "msg_emote": GRN "�i�g�s���j%s"NOR,
                        "cost": 0,
                        "club_only":1,
                        "club_name":"�g�s��",
                        "club_id":"dragon",
		]),
        "moon":([       "msg_speak": GRN "�i��ڡj%s: %s\n" NOR,
                        "msg_emote": GRN "�i��ڡj%s"NOR,
                        "cost": 0,
                        "club_only":1,
                        "club_name":"���",
                        "club_id":"moon",
		]),
        "sky":([       "msg_speak": GRN "�i�Ѧa�|�j%s: %s\n" NOR,
                        "msg_emote": GRN "�i�Ѧa�|�j%s"NOR,
                        "cost": 0,
                        "club_only":1,
                        "club_name":"�Ѧa�|",
                        "club_id":"sky",
		]),
        "ming":([       "msg_speak": GRN "�i���Сj%s: %s\n" NOR,
                        "msg_emote": GRN "�i���Сj%s"NOR,
                        "cost": 0,
                        "club_only":1,
                        "club_name":"����",
                        "club_id":"ming",
		]),
	"sam" : ([	"msg_speak": GRN"�i�ѩ��j%s: %s\n"NOR,
			"msg_emote": GRN"�i�ѩ��j%s: %s\n"NOR,
			"cost": -1,
			"club_only": 1,
			"club_name": ({"�Ѧa�|", "����"}),
			"club_id": ({"sky", "ming"}),
	]),
        "god":([       "msg_speak": GRN "�i���ڡj%s: %s\n" NOR,
                        "msg_emote": GRN "�i���ڡj%s"NOR,
                        "cost": 0,
                        "club_only":1,
                        "club_name":"����",
                        "club_id":"god",
                ]),
        "bala": ([     "msg_speak": BGRN+WHT+" �ݼ� "+NOR+GRN+" %s�R"+NOR+"%s\n" NOR,
                        "msg_emote":BGRN+WHT+" �ݼ� "+NOR+GRN+" %s"NOR,
                        "cost": -1,
                ]),


]);
 
void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
}
int can_tune(string channel_id,object me)
{
	if(undefinedp(channels[channel_id])) return 0;
	if(wizardp(me)) return 1;
	if(!undefinedp(channels[channel_id]["wiz_only"]) && undefinedp(channels[channel_id]["player_listen"])) return 0;
	if(!undefinedp(channels[channel_id]["club_only"]))
	{
		if(CLUB_D->check_member(channels[channel_id]["club_id"],getuid(me)) < 1) return 0;
	}
	return 1;
}
int undefined_channel(string channel_item)
{
	if(member_array(channel_item,channel_list)==-1) return 1;
	else return 0;
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
        object *ob,asker,debuger;
        string *tuned_ch, who, mud;
 	int i,j,check;
 	mapping semote;
	//if(emote!=1) emote=0;



        if( verb== "" ) return 0;
        if( verb[<1] == '*' && !emote) 
	{
                emote = 1;
                verb = verb[0..<2];
        }
  if(wizardp(me)) arg = color(arg,emote);  // ansi color  (current -- wizard only)
        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;
//        if(debuger = find_living("luky")) message( "channel:sys",sprintf("%O ask do_channel()...\n",me), debuger );
	if(me->query_temp("netdead"))
	{
		if(!arg) return 0;
		who = HIB+"�i�t�Ρj"+me->name_id(1)+arg+"\n"+NOR;
		message( "channel:sys", who,
                         filter_array(users(), "filter_listener", this_object(),channels["sys"]));
		return 1;
	}
        if( userp(me) ) 
	{
		if( (me->query("talk_point") + channels[verb]["cost"]) < 0 && !wizardp(me)) return notify_fail("�A�{�b�f������, �n���@�U�~���O�𻡸ܳ�!\n");
                if(channels[verb]["wiz_only"] && !wizardp(me) && !me->query_temp("netdead")) return 0;
                if(channels[verb]["intermud"] && me->query("id")=="guest" ) return notify_fail("���[�̵L�k�ϥκ����W�D�C\n");
                if(channels[verb]["club_only"] 
                   && CLUB_D->check_member(channels[verb]["club_id"],getuid(me)) < 1
                   && !wizardp(me) ) return 0;
		if(channels[verb]["world"])
		{
			string *world=({"�i�j�N�j","�i�{�N�j","�i���ӡj"});

			i = NATURE_D->which_world(environment(me));
			if( !i || i==0 ) return notify_fail("�A�ҳB���ɪŨä��ݩ����ɥN�A�ҥH�L�k�ϥ�chat�C\n");
			channels[verb]["world"] = i;
			channels[verb]["msg_speak"] = HIG+world[i-1]+"%s�R"+NOR+"%s\n"+NOR;
			channels[verb]["msg_emote"] = HIG+world[i-1]+"%s"+NOR;
			if( i != channels[verb]["world"] ) return notify_fail("�A�ϥΪ��W�D���~�C\n");
		} 
                if(!wizardp(me) && arg==(string)me->query_temp("last_channel_msg") )
                        return notify_fail("�Υ���W�D���ܽФ��n���ƬۦP���T���C\n");
                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) ) me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 ) me->set("channels", tuned_ch + ({ verb }) );
        } else if(me->query("creater")) return 0; //����Ǫ���chat
 
/* By Tmr
        if( channels[verb]["anonymous"]) who = channels[verb]["anonymous"];
        else if( userp(me) || !stringp(who = me->query("channel_id")) )
             {
                if(me->query("id")) who = me->query("name") + "(" + capitalize(me->query("id")) + ")";
             	else if(!who = me->channel_id()) who = me->query("name") + "(Unknown)";
             } 
*/
     // Make the identity of speaker.

    if( channels[verb]["anonymous"]
    && (!userp(me) || wizardp(me) || random(CHANCE)))
        who = channels[verb]["anonymous"];
    else {
        who = me->query("channel_id");
        if( ! stringp(who) )
            who = sprintf("%s(%s)", me->name(1), capitalize(me->query("id")));
    }

             //else who="";//�ץ�inter_mud���D

        // Ok, now send the message to those people listening us.
        ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
//        if( !arg ) arg = "...";
        if(emote) 
	{
                string msg,vb,emote_arg;
                msg="";
                if( !channels[verb]["msg_emote"] ) return notify_fail("�o���W�D���� emote�C\n");
//                if( !arg || !stringp(arg) || arg=="" ) return notify_fail("�W�Demote���O���~, ��H�L�k�P�_�C\n");
                if (!arg)
                {
/*
                	if(stringp(channels[verb]["anonymous"])) arg = channels[verb]["anonymous"]+"�y�W�S�X�@�ƵL���H�諸���C\n";
                	else arg = (string)me->name()+"�y�W�S�X�@�ƵL���H�諸���C\n";
*/
                         arg = who+"�y�W�S�X�@�ƵL���H�諸���C\n";
                }
                else 
		{
//			if(debuger=find_player("luky")) tell_object(debuger,sprintf("start: %s\n",arg));
			//�O�_��gfinger_a.c�^���T��.
			if(asker = me->query("channel_asker"))
			{
				if(!emote_arg=me->query("channel_target")) return 1;
				vb=me->query("channel_verb");
				who=asker->query("name")+"("+capitalize(asker->query("id"))+"@"+INTERMUD_MUD_NAME+")";
				semote = EMOTE_D->query_emote(vb);
				arg=semote["others_target"];
				arg = replace_string(arg, "$N", who);
		                arg = replace_string(arg, "$n", emote_arg);
		                arg = replace_string(arg, "$T", "");
//				if(debuger=find_player("luky")) tell_object(debuger,sprintf("hit:%O %s %s %d %s\n%s\n",asker, vb, emote_arg, REMOTE_CHANNEL_EMOTE, channels[verb]["anonymous"],arg));
            	//		if( !undefinedp(channels[verb]["intermud"]) )
            	//		channels[verb]["intermud"]->send_msg( channels[verb]["channel"],
            	//				  getuid(asker),
            	//				  asker->name(1),
            	//				  arg,
            	//				  1,
            	//				  channels[verb]["filter"] );
            			//return 1;
			}
                        else
                        {
                        	
//                        	if(debuger=find_player("luky")) tell_object(debuger,sprintf("Miss!! %s\n","\n"));
                        	if(living(me))
                        	{
	                        	if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) 
					{
		                                vb = arg;
		                                emote_arg = "";
		                        }
		                        
		                        if( !undefinedp(channels[verb]["intermud"]) )
		                        {
		                        	//�O�_���ﻷ�ݹ�H��emote.  "verb who@mud"
		                        	if(sscanf(emote_arg, "%s@%s", who, mud)== 2) {
		                        		GFINGER_Q->send_finger_q(mud, who, this_player(1),sprintf("%s#%s",verb,vb));
		                        		write("�z�L�����n�D�d�߻ݭn�@�I�ɶ��A�еy��C\n");
		                        		return 1;
		                        	}
//                                                 else arg = EMOTE_D->do_emote(me, vb, emote_arg, NET_CHANNEL_EMOTE, channels[verb]["anonymous"]);
                                                  else arg = EMOTE_D->do_emote(me, vb, emote_arg, NET_CHANNEL_EMOTE, who);
		                        }
/*
                                          else if( !undefinedp(channels[verb]["anonymous"]) ) arg = EMOTE_D->do_emote(me, vb, emote_arg, ANONYMOUS_CHANNEL_EMOTE, channels[verb]["anonymous"]);
                                          else arg = EMOTE_D->do_emote(me, vb, emote_arg, LOCAL_CHANNEL_EMOTE, channels[verb]["anonymous"]);
*/
                                          else if( !undefinedp(channels[verb]["anonymous"]) ) arg = EMOTE_D->do_emote(me, vb, emote_arg, ANONYMOUS_CHANNEL_EMOTE, who);
                                          else arg = EMOTE_D->do_emote(me, vb, emote_arg, LOCAL_CHANNEL_EMOTE, who);

                        	}
                        }
                        if(!arg)
                        {
                        	if(me->is_character())
                        	{
                        		if(!undefinedp(channels[verb]["anonymous"])) arg=channels[verb]["anonymous"]+vb+" "+emote_arg+"\n";
                        		else arg=me->name()+vb+" "+emote_arg+"\n";
                        	}
                        	else arg=vb+" "+emote_arg+"\n";
                        }
                }
                if(!arg) return 0;
                msg = sprintf( channels[verb]["msg_emote"], arg );
		
		if(channels[verb]["world"])
		{
			if(!msg) msg="";
			i = NATURE_D->which_world(environment(me));
			message( "world_channel:world"+(string)i+":"+verb, msg, ob );
		}
                else
                {
			if(!msg) msg="";
			message( "channel:"+verb,msg, ob );
		}
        }
        else
	{
		if(channels[verb]["world"])
		{
			if(!arg) arg="...";
			i = NATURE_D->which_world(environment(me));
			message( "world_channel:world"+(string)i+":"+verb,
                		sprintf( emote ? channels[verb]["msg_emote"] : channels[verb]["msg_speak"], who, arg ), ob );
		//�����H�dż��
//			for(j=0;j<sizeof(banned_words);j++)
//			{
//				if(strsrch(arg, banned_words[j],1))
//				{
//					check=1;
//					break;
//				}
//			}
		        if( userp(me) && check )
		        {
		        	log_file( "static/channel", "["+ctime(time())[4..18]+"] "+getuid(me)+":" + sprintf( emote ? channels[verb]["msg_emote"] : channels[verb]["msg_speak"], who, arg ) );
				check=0;
			}
		}
           	else
           	{
           		if(!arg) arg="...";
			message( "channel:" + verb, sprintf( channels[verb]["msg_speak"], who, arg ), ob );
		//�����H�dż��
//			for(j=0;j<sizeof(banned_words);j++)
//			{
//				if(strsrch(arg, banned_words[j],1))
//				{
//					check=1;
//					break;
//				}
//			}
		        if( userp(me) && check )
		        {
		        	log_file( "static/channel", "["+ctime(time())[4..18]+"] "+getuid(me)+":" + sprintf( channels[verb]["msg_speak"], who, arg ) );
		        	check=0;
		        }
		}
		
	}
        //�ˬd�ݽ֩�����
	if (channels[verb]["anonymous"])
        {
		string msg;
                if (userp(me)) who = me->query("name")+"("+capitalize(me->query("id"))+")";
                msg = replace_string(arg, channels["rumor"]["anonymous"], who);
                msg = sprintf(channels["sys"]["msg_speak"], who, arg);
                message( "channel:sys", msg,
                         filter_array(ob, "filter_listener", this_object(),channels["sys"]));

        }
        if( arrayp(channels[verb]["extra_listener"]) ) 
	{
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
	//�����W�D
        if( !undefinedp(channels[verb]["intermud"]) && base_name(me) != channels[verb]["intermud"] )
            channels[verb]["intermud"]->send_msg( channels[verb]["channel"],
            					  getuid(me),
            					  me->name(1),
            					  arg,
            					  emote,
            					  channels[verb]["filter"] );
 
        if( userp(me) && !wizardp(me) ) //����
        {
                me->set_temp("last_channel_msg", arg);
 		me->add("talk_point", channels[verb]["cost"] );
 	}
        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        if( !environment(ppl) ) return 0;
        if( ch["player_listen"] ) return 1;
        if( ch["wiz_only"] ) return wizardp(ppl);
        if( wizardp(ppl) ) return 1; 
        if( ch["club_only"] && CLUB_D->check_member(ch["club_id"],getuid(ppl)) < 1 ) return 0;
        return 1;
}

void register_relay_channel(string channel)
{
        object ob;
 
        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) 
	{
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}

string *query_channel_list()
{
	return channel_list;
}
string color(string arg, int emote)
{
  int i;
  string *source_color, *target_color;
  mapping color = ([
  "$U$" : U,
  "$BLK$" : HIW+BLK,
  "$WHT$" : NOR+WHT,
  "$HIW$" : HIW,
  "$RED$" : NOR+RED,
  "$HIR$" : HIR,
  "$GRN$" : NOR+GRN,
  "$HIG$" : HIG,
  "$YEL$" : NOR+YEL,
  "$HIY$" : HIY,
  "$BLU$" : NOR+BLU,
  "$HIB$" : HIB,
  "$MAG$" : NOR+MAG,
  "$HIM$" : HIM,
  "$CYN$" : NOR+CYN,
  "$HIC$" : HIC,
  "$NOR$" : NOR
  ]);

  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    if(arg && !emote) arg = replace_string(arg, source_color[i], target_color[i]);
    if(arg && !emote) arg += NOR;

  return arg;
}
