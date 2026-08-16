# Push_swap

*Projet réalisé dans le cadre du programme 42 par VSeker et CAtsin_Kousso.*

## Description du projet

Le projet `push_swap` est un exercice fondamental du cursus 42, visant à créer un programme en langage C permettant de trier des listes de différentes manières.

### Objectif

L'objectif principal est de maîtriser le concept de complexité algorithmique, notamment par la modification d'algorithmes de base en fonction de contraintes.

### Aperçu

`push_swap` se compose de quatre ensembles principaux de fonctions :

1. **Fonctions de parsing** — `parse_flags`, `parse_args`.
2. **Fonctions d'opérations possibles** — `pa`, `pb`.
3. **Fonctions d'algorithmes** — `simple_sort`, `medium_sort`.
4. **Fonctions utiles** — `ft_printf`, `ft_strcmp`.

## Instructions d'utilisation

Cette section explique comment compiler et utiliser `push_swap`.

### Cloner le dépôt

Pour tester le programme, clonez le dépôt dans le répertoire de votre choix :

```bash
git clone <URL_DU_DEPOT>
cd push_swap-public-
```

### Compilation

Placez-vous à la racine du dépôt et exécutez :

```bash
make
```

Cette commande crée l'exécutable `push_swap` à la racine du dépôt.

### Flags et exécution

À l'exécution, fournissez une liste de nombres à trier en arguments.

> **Attention :** seul le premier argument peut être une liste de nombres.

Par défaut, le programme affiche les opérations effectuées avec l'algorithme `adaptive`.

| Flag | Fonction |
|---|---|
| `--bench` | Affiche un benchmark résumant notamment l'algorithme et le nombre d'opérations utilisées. |
| `--simple` | Force l'utilisation de l'algorithme `simple`. |
| `--medium` | Force l'utilisation de l'algorithme `medium`. |
| `--complex` | Force l'utilisation de l'algorithme `complex`. |
| `--adaptive` | Force l'utilisation de l'algorithme `adaptive`. |

Exemples :

```bash
./push_swap 4 67 3 87 23
./push_swap --bench 4 67 3 87 23
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

## Ressources

- **Documentation 42 — Sujet Push_swap :** contient les exigences du projet.
- **Utilisation de l'intelligence artificielle (IA) :** l'IA n'a pas été utilisée pour générer le code source du programme.

## Ordre de fonctionnement et répartition des tâches

Cette section présente les différents ensembles de tâches réalisées et leur objectif.

### 1. Parsing et gestion des erreurs

**Par CAtsin_Kousso, revu par VSeker**

| Fonction | Rôle |
|---|---|
| `parse_flags` | Vérifie l'existence et parse les flags. |
| `parse_args` | Vérifie l'existence et parse les arguments tout en gérant les erreurs. |
| `test_args` | Vérifie que les arguments sont bien des nombres. |
| `check_duplicates` | Vérifie l'existence de doublons parmi les arguments. |
| `args_to_tab` | Place les valeurs des arguments dans un tableau. |
| `tab_to_list` | Place les valeurs du tableau dans une liste et leur attribue les index de la liste triée. |

### 2. Bench et fonctions utiles

**Par CAtsin_Kousso, revu par VSeker**

| Fonction | Rôle |
|---|---|
| `bench_count` | Compte les opérations au fur et à mesure. |
| `bench_print` | Affiche le résultat du benchmark. |
| `ft_split` | Permet de séparer les arguments. |
| `ft_isdigit` | Vérifie que les arguments sont des nombres. |
| `ft_atol` | Transforme une chaîne de caractères en `long int`. |

### 3. Opérations possibles

**Par VSeker, revu par CAtsin_Kousso**

| Fonction | Rôle |
|---|---|
| `pa` | Déplace la valeur du dessus de `b` au-dessus de `a`. |
| `pb` | Déplace la valeur du dessus de `a` au-dessus de `b`. |
| `rra` | Déplace la valeur du dessous de `a` au-dessus de `a`. |
| `rrb` | Déplace la valeur du dessous de `b` au-dessus de `b`. |
| `rrr` | Effectue simultanément `rra` et `rrb`. |
| `ra` | Déplace la valeur du dessus de `a` au-dessous de `a`. |
| `rb` | Déplace la valeur du dessus de `b` au-dessous de `b`. |
| `rr` | Effectue simultanément `ra` et `rb`. |
| `sa` | Inverse les deux valeurs du dessus de `a`. |
| `sb` | Inverse les deux valeurs du dessus de `b`. |
| `ss` | Effectue simultanément `sa` et `sb`. |

### 4. Algorithmes

**Par VSeker, revu par CAtsin_Kousso**

| Fonction | Rôle |
|---|---|
| `simple_sort` | Applique un algorithme d'ordre simple `O(n²)` adapté aux contraintes. |
| `medium_sort` | Applique un algorithme d'ordre medium `O(n√n)` adapté aux contraintes. |
| `complex_sort` | Applique un algorithme d'ordre complex `O(n log n)` adapté aux contraintes. |
| `adaptive_sort` | Sélectionne les algorithmes précédents en fonction du nombre d'arguments et du désordre. |
