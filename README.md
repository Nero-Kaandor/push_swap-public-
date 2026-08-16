## libft : Votre Propre Bibliothèque C

*Ce projet a été créé dans le cadre du programme 42 par VSeker && CAtsin_Kousso*.
---

### Description du Projet

Le projet `push_swap` est un exercice fondamental du cursus 42, visant à créer un **programme** de base en groupe en langage C. Celui-ci permet de trier des listes de differentes manières.

#### Objectif
L'objectif principal est de maîtriser le concept de complexité algorithmique **en groupe**, notamment **par la modification d'algorithmes de bases en fonction de contraintes**

#### Aperçu
`push_swap` se compose de 4 ensembles principaux de fonctions :
1.  **Fonctions de parsing** (par exemple : `parse_flags`, `parse_args`).
2.  **Fonctions d'operations possibles** (par exemple : `pa`, `pb`).
3.  **Fonctions d'algorithmes** (par exemple : `simple_sort`, `medium_sort`).
4.  **Fonctions utiles** (par exemple : `ft_printf`, `ft_strcmp`).

---

### Instructions d'Utilisation

Cette section explique comment compiler et utiliser `push_swap`.

#### Clone
Pour tester le programme seul, executez la commande suivante dans le fichier ou vous souhaitez creer
le programme :
`git clone nomdudepotgit`

#### Compilation
Pour compiler le programme, placez-vous à la racine du dépôt et exécutez la commande `make` :

`make`

Ceci créera le fichier executable nommé push_swap à la racine du dépôt.

#### Flags et execution
A l'execution, vous donnerez une liste de nombre a trier en arguments 
ATTENTION seul votre premier arguments peut etre une liste de nombres
vous pouvez dans ce cas afficher :
- par defaut le programme affiches les operations effectuées avec un algo "adaptive".
- si vous ajoutez le flag (entre l'appel du programme et les arguments) `--bench` le programme affiche un "bench" qui resume en plus l'algorithme et les operations utilisées.
- si vous ajoutez le flag (entre l'appel du programme et les arguments) `--simple`, `--medium`, `--complex`, `--adaptive` vous forcez l'algorithme de tri utilisé.

---

### Ressources

Documentation 42 - Sujet libft : Contient Les exigences du programme.

Utilisation de l'Intelligence Artificielle (IA)
L'IA n'a pas été utilisée pour générer le code source du programme.

---

### Ordre de fonctionnement et repartition des taches

Cette section liste les ensembles de taches realisees en détaillant leur but.

#### 1. Parsing et gestion des erreurs (by CAtsin_Kousso revu par VSeker)
| Fonctions principales | But |
| `parse_flags` | Vérifie l'existence et parse les flags. |
| `parse_args` | Vérifie l'existence et parse les arguments tout en gerant les erreurs.|
| `test_args` | Vérifie si le premier argument et que les arguments sont bien des nombre.|
| `check_duplicates` | Vérifie l'existence de doublon d'arguments.|
| `args_to_tab` | Mets les valeurs des arguments dans un tableau. |
| `tab_to_list` | Mets les valeurs du tableau dans une liste et en change les index pour y mettre les index de la liste triee. |

#### 2. Bench et fonctions utiles (by CAtsin_Kousso revu par VSeker)
| Fonctions principales | But |
| `bench_count` | Compte les operations au fur et a mesure |
| `bench_print` | Compte les operations au fur et a mesure |
| `ft_split` | Pour split les arguments |
| `ft_isdigit` | Pour verifier que les arguments sont bien des nombre |
| `ft_atol` | Transforme une chaine de carateres en long int |

#### 3. Operations possibles (by VSeker revu par CAtsin_Kousso)
| Fonctions principales | But |
| `pa` | Deplace la valeur du dessus de b au dessus de a |
| `pb` | Deplace la valeur du dessus de a au dessus de b |
| `rra` | Deplace la valeur du dessous de a au dessus de a |
| `rrb` | Deplace la valeur du dessous de b au dessus de b |
| `rrr` | fait simultanement rra et rrb |
| `ra` | Deplace la valeur du dessus de a au dessous de a |
| `rb` | Deplace la valeur du dessus de b au dessous de b |
| `rr` | fait simultanement ra et rb |
| `sa` | Inverse les deux valeurs du dessus de a |
| `sb` | Inverse les deux valeurs du dessus de b |
| `ss` | fait simultanement sa et sb |

#### 4. Algorithmes (by VSeker revu par CAtsin_Kousso)
| Fonctions principales | But |
| `simple_sort` | Applique un algo d'ordre simple O(n²) adapté aux contraintes |
| `medium_sort` | Applique un algo d'ordre medium (O(n√n)) adapté aux contraintes |
| `complex_sort` | Applique un algo d'ordre complex (O(n log n)) adapté aux contraintes |
| `adaptive_sort` | Applique les algos precedents en fonction du nombre d'arguments et du desordre |


