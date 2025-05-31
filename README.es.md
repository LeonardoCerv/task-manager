# Sistema de Gestión de Tareas en C++
[![Language](https://img.shields.io/badge/code-C++-blue.svg?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Field](https://img.shields.io/badge/Field-Programación%20Orientada%20a%20Objetos-purple)]()

Una aplicación integral de gestión de tareas desarrollada en C++ que demuestra principios avanzados de programación orientada a objetos, herencia, polimorfismo y patrones de diseño modular.

## Descripción General

Este proyecto implementa un sistema completo de gestión de tareas que permite a los usuarios organizar sus responsabilidades personales y profesionales a través de una interfaz de línea de comandos intuitiva. La aplicación muestra prácticas sofisticadas de ingeniería de software incluyendo clases abstractas, jerarquías de herencia y relaciones de composición.

### Características Principales

- **Categorías Duales de Tareas**: Manejo separado de tareas personales y relacionadas con el trabajo con atributos especializados
- **Listas de Tareas Personalizadas**: Crear y gestionar múltiples colecciones categorizadas de tareas
- **Sistema de Recordatorios**: Asociar recordatorios basados en tiempo con tareas individuales
- **Gestión de Prioridades**: Asignar y rastrear prioridades de tareas para mejor organización
- **Gestión Dinámica de Memoria**: Uso eficiente de punteros y vectores para estructuras de datos escalables

## Arquitectura Técnica

El sistema emplea un diseño orientado a objetos limpio con los siguientes componentes principales:

### Jerarquía de Clases
- **`Tarea` (Clase Base Abstracta)**: Define la interfaz fundamental de tareas con métodos virtuales puros
- **`TareaTrabajo`**: Hereda de `Tarea`, especializada para tareas de trabajo con fechas de entrega
- **`TareaPersonal`**: Hereda de `Tarea`, diseñada para gestión de tareas personales
- **`Lista`**: Gestiona colecciones de tareas con relaciones de composición
- **`Usuario`**: Controlador central que gestiona interacciones de usuario y persistencia de datos
- **`Recordatorio`**: Encapsula la funcionalidad de recordatorios con gestión de fecha/hora

### Patrones de Diseño Aplicados
- **Herencia y Polimorfismo**: La clase base abstracta permite polimorfismo en tiempo de ejecución
- **Composición**: Las listas contienen objetos de tareas, los usuarios contienen tanto listas como tareas
- **Encapsulación**: Variables miembro privadas con acceso controlado a través de getters/setters
- **Principios RAII**: Gestión apropiada de recursos a través de constructores y destructores

### Validación de Entrada y Manejo de Errores
La aplicación implementa varios mecanismos de verificación de restricciones:
- Validación de límites de índice para operaciones de arreglos
- Verificación de tipos para entrada de usuario (aunque con limitaciones conocidas para tipos de entrada mixtos)
- Verificación de existencia antes de operaciones de eliminación

## Enfoque de Resolución de Problemas

Este proyecto aborda el desafío del mundo real de la gestión de productividad personal mediante:

1. **Representación de Datos**: Uso de contenedores STL (`vector`) para almacenamiento dinámico de datos
2. **Seguridad de Tipos**: Aprovechamiento del tipado fuerte de C++ para prevenir errores en tiempo de ejecución
3. **Diseño Modular**: Separación de responsabilidades a través de múltiples archivos de encabezado para mantenibilidad
4. **Experiencia de Usuario**: Implementación de un sistema de menú interactivo para navegación intuitiva

## Diagrama de Clases
![Diagrama de Clases](Diagrama%20UML.png)

## Competencias Técnicas Demostradas

Este proyecto cumple con varios resultados de aprendizaje del plan de estudios de Programación Orientada a Objetos:

### SEG0702 - Evaluación e Implementación de Tecnología
- **Aplicado**: Evaluación de contenedores STL de C++ vs. arreglos sin procesar para gestión dinámica de datos
- **Implementado**: Características modernas de C++ incluyendo contenedores vector y gestión inteligente de memoria
- **Demostrado**: Apertura para explorar patrones de diseño alternativos para soluciones óptimas

### SICT0301 - Análisis de Componentes y Pensamiento Computacional
- **Aplicado**: Descompuso el problema de gestión de tareas en componentes distintos y manejables
- **Demostrado**: Comprensión de principios computacionales a través de organización algorítmica de tareas
- **Implementado**: Principios de ingeniería en diseño de software con clara separación de responsabilidades

### SICT0303 - Resolución de Problemas Complejos
- **Resuelto**: Gestión de relaciones de datos multicapa (usuarios → listas → tareas → recordatorios)
- **Implementado**: Jerarquías de herencia para manejar diversos tipos de tareas eficientemente
- **Aplicado**: Patrones de diseño orientados a objetos para crear código escalable y mantenible

## Comenzando

### Prerrequisitos
- Compilador de C++ (se recomienda g++)
- Soporte de la Biblioteca de Plantillas Estándar (STL)

### Compilación y Ejecución
```bash
g++ -o task_manager main.cpp
./task_manager
```

### Uso
Sigue las instrucciones del menú interactivo para:
1. Crear y gestionar tareas personales/de trabajo
2. Organizar tareas en listas personalizadas
3. Establecer recordatorios para fechas límite importantes
4. Rastrear el estado de finalización de las tareas


## Reflexion Final

Este proyecto profundizó significativamente mi comprensión de la programación orientada a objetos mientras destacaba áreas para crecimiento futuro. El aspecto más desafiante fue diseñar la jerarquía de herencia para representar adecuadamente diferentes tipos de tareas mientras se mantiene la reutilización de código. Trabajar con clases abstractas y funciones virtuales puras me enseñó el poder del polimorfismo, aunque inicialmente luché con la gestión de punteros antes de ganar confianza a través del desarrollo iterativo.

**Limitaciones Principales Encontradas:**
- La validación de entrada necesita mejoramiento (particularmente para entrada numérica/texto mixta)
- La verificación de límites de índice podría ser más robusta (índices negativos causan fallos)
- Sin almacenamiento persistente de datos (los datos existen solo durante la ejecución)

**Crecimiento Técnico:**
El proyecto me llevó más allá de solo "hacer que funcione" hacia crear código mantenible y bien estructurado. Implementar relaciones de composición entre usuarios, listas y tareas me mostró cómo sistemas complejos emergen de componentes simples y bien definidos. Más importante, aprendí que la ingeniería de software trasciende la sintaxis y algoritmos—se trata de entender las necesidades del usuario y traducirlas en soluciones confiables.

**Visión Futura:**
Aunque funcional, este sistema podría beneficiarse de E/S de archivos para persistencia, manejo integral de excepciones, bibliotecas modernas de fecha/hora, y potencialmente una interfaz gráfica. Estas limitaciones representan oportunidades para aprendizaje continuo y evolución del sistema.