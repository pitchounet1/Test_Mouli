pipeline {
    agent {
        docker {
            image 'epitech/epitech-docker'  // Utiliser l'image Docker d'Epitech
            args '-v /workspace:/workspace'  // Monter un volume pour les fichiers du projet
        }
    }

    environment {
        CC = 'gcc'  // Utiliser GCC comme compilateur
        CFLAGS = '-Wall -Wextra -Werror'  // Options de compilation
    }

    stages {
        stage('Setup') {
            steps {
                // Vérifier que GCC, Make et Git sont disponibles dans l'image Docker d'Epitech
                sh 'gcc --version'  // Vérifier si GCC est installé
                sh 'make --version'  // Vérifier si Make est installé
                sh 'git --version'  // Vérifier si Git est installé
            }
        }

        stage('Clone') {
            steps {
                // Cloner votre projet Git
                git 'https://github.com/username/projet.git'
            }
        }

        stage('Build') {
            steps {
                // Compiler le projet avec GCC et Make
                sh 'make'  // Lancer la compilation avec Make
            }
        }

        stage('Test') {
            steps {
                // Si vous avez des tests à exécuter
                sh './tests.sh'
            }
        }
    }

    post {
        always {
            cleanWs()  // Nettoyer le workspace après chaque build
        }
        success {
            echo 'Build réussi !'
        }
        failure {
            echo 'Le build a échoué.'
        }
    }
}
