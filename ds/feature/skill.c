// skill.c

#include <ansi.h>
#include <dbase.h>

int inactive;

mapping skills;
mapping learned;
mapping skill_map;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

int is_inactive() { return inactive; }
int set_inactive(int flag)
{
	if(!flag) inactive=0;
	else inactive=1;
}

void skill_setup(int level)
{
	int skill_level;
	if(userp(this_object())) return;
	skill_level=level*3;
	if(skill_level>100) skill_level=100;
	if( !mapp(skills) ) skills = ([ "unarmed": skill_level ]);
	switch(query("race"))
	{
		case "beast":
		case "zerg":
			if( undefinedp(skills["unarmed"]) ) skills["unarmed"]=skill_level;
			if( undefinedp(skills["dodge"]) ) skills["dodge"]=skill_level;
			if( undefinedp(skills["parry"]) ) skills["parry"]=skill_level;
			if( undefinedp(skills["block"]) ) skills["block"]=skill_level;
			if( undefinedp(skills["combat"]) ) skills["combat"]=skill_level;
			if( undefinedp(skills["perception"]) ) skills["perception"]=skill_level/2;
			break;
		case "human":
		case "protoss":
		case "robot":
		default:
			if( undefinedp(skills["unarmed"]) ) skills["unarmed"]=skill_level;
			if( undefinedp(skills["dodge"]) ) skills["dodge"]=skill_level;
			if( undefinedp(skills["parry"]) ) skills["parry"]=skill_level;
			if( undefinedp(skills["block"]) ) skills["block"]=skill_level;
			if( undefinedp(skills["bow"]) ) skills["bow"]=skill_level;
			if( undefinedp(skills["sword"]) ) skills["sword"]=skill_level;
			if( undefinedp(skills["fork"]) ) skills["fork"]=skill_level;
			if( undefinedp(skills["blade"]) ) skills["blade"]=skill_level;
			if( undefinedp(skills["axe"]) ) skills["axe"]=skill_level;
			if( undefinedp(skills["whip"]) ) skills["whip"]=skill_level;
			if( undefinedp(skills["combat"]) ) skills["combat"]=skill_level;
			if( undefinedp(skills["ride"]) ) skills["ride"]=skill_level;
			if( undefinedp(skills["perception"]) ) skills["perception"]=skill_level/2;
	}
	return;
}

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: 沒有此SKILL (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: 沒有此SKILL (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

varargs void clear_map_skill(int flag)
{
 skill_map=0;
 this_object()->reset_action();
 return;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
	int s=0,j,k,l=0;
	string *eff_limbs;
	s = query_temp("apply/sk_" + skill);
	s += query_temp("spell/sk_" + skill);
	if( mapp(skills) )
	{
		if(raw==1) return skills[skill];
		s += skills[skill];
		if(raw==2)
		{
			eff_limbs=query("limbs_effect/skill");
 			j=sizeof(eff_limbs);
 			if(j)
 			{
 				for(k=0;k<j;k++) l+=query("wound/"+eff_limbs[k]);
 				l/=j;
 				s = s - (s * l)/110;
 			}
			return s;
		}
		if( mapp(skill_map) )
			s += skills[skill_map[skill]];
		eff_limbs=query("limbs_effect/skill");
 		j=sizeof(eff_limbs);
 		if(j)
 		{
 			for(k=0;k<j;k++) l+=query("wound/"+eff_limbs[k]);
 			l/=j;
 			s = s - (s * l)/110;
 		}
	}
  return s;
}

mapping query_skill_map()
{
	return skill_map;
}

int skill_death_penalty()
{
	string *sk;
	int i;

	if( wizardp(this_object()) || !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++) {
			if(random(2)) skills[sk[i]]--;
         if( this_object()->query_temp("killer") )
           	skills[sk[i]] = skills[sk[i]] - 3 - random(3);
			if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				map_delete(learned, sk[i]);
			else {
				if(random(2)) skills[sk[i]]--;
            if( this_object()->query_temp("killer") )
              	skills[sk[i]] = skills[sk[i]] - 3 - random(3);
				if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
			}
		}
	skill_map = 0;
	return 1;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
         int integ, maxlevel;

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	if(inactive) return;
	if( !weak_mode || !userp(this_object()) )
	{
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

  /*      rate=random(24);
        if(rate< 4 && amount >1) amount=1;
        else if(rate < 6  && amount >2) amount=amount/2+1;
        else if(rate==23) amount*=2;
*/
	
	//等級限制
	switch(this_object()->query("level"))
	{
		case 1:		maxlevel=19; break;
		case 2:		maxlevel=25; break;
		case 3:		maxlevel=30; break;
		case 4:		maxlevel=35; break;
		case 5:		maxlevel=39; break;
		case 6:		maxlevel=43; break;
		case 7:		maxlevel=47; break;
		case 8:		maxlevel=51; break;
		case 9:		maxlevel=55; break;
		case 10:	maxlevel=59; break;
		case 11:	maxlevel=63; break;
		case 12:	maxlevel=67; break;
		case 13:	maxlevel=71; break;
		case 14:	maxlevel=75; break;
		case 15:	maxlevel=79; break;
		case 16:	maxlevel=82; break;
		case 17:	maxlevel=85; break;
		case 18:	maxlevel=88; break;
		case 19:	maxlevel=91; break;
		case 20:	maxlevel=93; break;
		case 21:	maxlevel=95; break;
		case 22:	maxlevel=97; break;
		case 23:	maxlevel=98; break;
		case 24:	maxlevel=99; break;
		case 25:	maxlevel=100; break;
		default: maxlevel=100; break;
	}

	if(skills[skill] >= maxlevel) return;
	
	if(skills[skill] < SKILL_D(skill)->improve_limite(this_object()) )
	{

                // Give learning penalty to those learning too much skills.
                integ = query("int") + query_temp("apply/int"); // consider the extra int (from eq/magic/spells/etc)
                if( sizeof(learned) > integ )
                        amount /= sizeof(learned) - integ;


		if( !amount ) amount = 1;

		if( !mapp(learned) ) learned = ([ skill : amount ]);
		else (int)learned[skill] += amount;

		if( (!weak_mode || !userp(this_object()))
		&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) * 2 )
		{
			skills[skill]++;
			learned[skill] = 0;
			if(skills[skill]>=maxlevel) tell_object(this_object(),HIG"你的「" + to_chinese(skill) + "」已經到達目前等級可修練的最高階段了﹗(提昇至"+skills[skill]+"級)\n" NOR);
			else tell_object(this_object(), HIC "你突然對「" + to_chinese(skill) + "」有了更深一層的領悟﹗(提昇至第"+skills[skill]+"級)\n" NOR);
			SKILL_D(skill)->skill_improved(this_object());
		}
	}
}

varargs void add_skill(string skill)
{
	if( !find_object(SKILL_D(skill)) && file_size(SKILL_D(skill)+".c") < 0 )
       		error("F_SKILL: No such skill (" + skill + ")\n");
       if( !mapp(skills) ) skills = ([ skill: 1 ]);
         else skills[skill]++;
	tell_object(this_object(), HIC "你的「" + to_chinese(skill) + "」經過一番練習後, 已經提昇至第 "+skills[skill]+"級了﹗\n" NOR);
	SKILL_D(skill)->skill_improved(this_object());
}
