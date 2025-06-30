# Matchstick

**Matchstick** est un jeu de bâtonnets en ligne de commande développé en C. Le but est simple : deux joueurs (un humain contre une IA) retirent à tour de rôle un certain nombre de bâtonnets. Celui qui retire **le dernier** a **perdu**.

---

## 🧠 Principe du jeu

- Une pyramide de bâtons est affichée (ex: 4 lignes avec 1, 3, 5, 7 bâtons).
- À chaque tour, le joueur choisit **une ligne** et retire entre **1 et `n` bâtons** (valeur maximale définie à l'exécution).
- Le jeu continue jusqu'à ce qu'il n'y ait **plus de bâtons**.
- Le joueur qui retire **le dernier bâton perd la partie**.

---

## 📦 Utilisation

### Compilation

```bash
make
```

```bash
./matchstick [number of lines] [number of matches per turn]
```

| Argument                     | Description                                                |
| ---------------------------- | ---------------------------------------------------------- |
| `number of lines`            | Nombre de lignes de bâtonnets dans la pyramide             |
| `number of matches per turn` | Nombre maximum de bâtonnets que l'on peut retirer par tour |

### 🎮 Exemple

```bash
./matchstick 4 3
```

Cela crée une pyramide de 4 lignes, et chaque joueur peut retirer entre 1 et 3 bâtons à son tour.

## 🤖 Jouabilité

- Le jeu alterne les tours entre le joueur humain et l’IA.

- L’IA suit une stratégie simple mais peut être battue avec un bon raisonnement.

- Le jeu gère les entrées invalides, les erreurs de ligne, de nombre de bâtons, etc.

## 🗂 Structure du projet

```
├── Makefile             # Compilation du projet
├── README.md            # Ce fichier
├── includes/            # Fichiers d'en-tête (.h)
│   ├── lib.h
│   └── matchstick.h
└── src/                 # Code source
    ├── computer.c       # IA
    ├── inter.c          # Interaction utilisateur
    ├── lib.c            # Fonctions utilitaires
    ├── main.c           # Point d'entrée
    ├── map.c            # Création / affichage de la map
    ├── matchstick.c     # Logique de jeu
    └── player.c         # Tour du joueur
```

## 🧰 Dépendances

- GCC ou un compilateur C compatible

## 📌 Auteurs

- Projet réalisé dans le cadre d’un apprentissage des bases de la programmation en C et de la logique algorithmique.