//Binary search algorithm 🔢
function binarySearch(arr, target) {
  let left = 0;
  let right = arr.length - 1;

  while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    if (arr[mid] === target) {
      return mid; // found at index mid
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; // not found
}


//Reversing a linked list (iteratively)
function reverseLinkedlist(linkedList_head){
  //have 3 pointers to track the posistion of the nodes.
  current = head;
  next = null;
  prev = null;

  while(current != null){
    next = current.next
    current.next = prev;
    prev = current;
    current = next;
  }
}


//TREE TRAVERSAL'S
function inorderTreeTraversal(rootNode){
  if(rootNode != null){
    inorderTreeTraversal(rootNode.left);
    console.log(rootNode.data);
    inoorderTreeTraversal(rootNode.right);
  }
}

function preorderTreeTraversal(rootNode){
  if(rootNode != null){
    console.log(rootNode.data);
    inorderTreeTraversal(rootNode.left);
    inoorderTreeTraversal(rootNode.right);
  }
}

function postorderTreeTraversal(rootNode){
  if(rootNode != null){
    inorderTreeTraversal(rootNode.left);
    inoorderTreeTraversal(rootNode.right);
    console.log(rootNode.data);
  }
}



//GRAPH TRAVERSAL'S
//-----------------------------------------------------------------//

//Depth first Search algorithm 🔢
function dfs(graph, start, visited = new Set()) {
  visited.add(start);

  for (const neighbor of graph[start]) {
    if (!visited.has(neighbor)) {
      dfs(graph, neighbor, visited);
    }
  }
}


//breadth first search algorithm 🔢
function bfs(graph, start) {
  const queue = [start];
  const visited = new Set([start]);

  while (queue.length > 0) {
    const current = queue.shift();

    for (const neighbor of graph[current]) {
      if (!visited.has(neighbor)) {
        queue.push(neighbor);
        visited.add(neighbor);
      }
    }
  }
}


